#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define print(msg) cout << msg << endl

struct TestCase
{
    struct TestFailed
    {};

    struct TestSkipped
    {};

    virtual ~TestCase()
    {}

    virtual void setUp()
    {}

    virtual void tearDown()
    {}

    virtual void run() = 0;

    const std::string& name() const
    {
	return name_;
    }

protected:
    void setName(const std::string& name)
    {
	name_ = name;
    }

private:
    std::string name_;
};

struct PassingTest : TestCase
{
    PassingTest()
    {
	setName("PassingTest");
    }

    void run()
    {}

private:
};

struct PassingTestThrowsNoExceptions : PassingTest
{
    PassingTestThrowsNoExceptions()
    {
	setName("PassingTestThrowsNoExceptions");
    }

    void run()
    {
	try
	{
	    PassingTest::run();
	}
	catch(...)
	{
	    throw TestCase::TestFailed();
	}
    }

private:
};

struct FailingTest : TestCase
{
    FailingTest()
    {
	setName("FailingTest");
    }

    void run()
    {
	throw TestFailed();
    }

private:
};

struct FailingTestThrowsTestFailed : FailingTest
{
    FailingTestThrowsTestFailed()
    {
	setName("FailingTestThrowsTestFailed");
    }

    void run()
    {
	bool success(false);

	try
	{
	    FailingTest::run();
	}
	catch(const TestCase::TestFailed& x)
	{
	    success = true;
	}

	if(!success)
	    throw TestCase::TestFailed();
    }
};

struct SkippedTest : TestCase
{
    SkippedTest()
    {
	setName("SkippedTest");
    }

    void run()
    {
	throw TestSkipped();
    }

private:
};

struct SkippedTestThrowsTestSkipped : SkippedTest
{
    SkippedTestThrowsTestSkipped()
    {
	setName("SkippedTestThrowsTestSkipped");
    }

    void run()
    {
	bool success(false);

	try
	{
	    SkippedTest::run();
	}
	catch(const TestCase::TestSkipped& x)
	{
	    success = true;
	}

	if(!success)
	    throw TestCase::TestFailed();
    }
};

struct TestRunner
{
    TestRunner()
	: testNumber_(0),
	  failed_(0),
	  skipped_(0)
    {}

    size_t getFailed() const
    {
	return failed_;
    }

    size_t getSkipped() const
    {
	return skipped_;
    }

    void runTests(std::vector<TestCase*>& tests)
    {
	print("Running " << tests.size() << " tests.");
	
	testNumber_ = 0;

	for(TestCase* t : tests)
	    runTest(t);
    
	printResult(failed_, skipped_);
    }

private:
    void printResult(size_t errs, size_t skips)
    {
	cout <<	(0 == errs ? "All tests PASSED": "One or more tests FAILED")
	     <<	(0 == skips ? "" : " (One or more tests SKIPPED)")
	     << endl;
    }

    void runTest(TestCase* test)
    {
	int previousFailed(failed_);
	int previousSkipped(skipped_);
	
	++testNumber_;
	test->setUp();
	tryTest(test);
	test->tearDown();
	
	print("\t" << testNumber_ << ". " << test->name() << ": " <<
	      (previousSkipped == skipped_ ? 
	       (previousFailed == failed_ ? "OK" : "NOT OK") : "SKIPPED"));
    }

    void tryTest(TestCase* test)
    {
	try
	{
	    test->run();
	}
	catch(const TestCase::TestFailed&)
	{
	    ++failed_;
	}
	catch(const TestCase::TestSkipped&)
	{
	    ++skipped_;
	}
    }

    size_t testNumber_;
    size_t failed_;
    size_t skipped_;
};

struct TestRunnerTest : TestCase
{
    TestRunnerTest()
	: runner_(),
	  tests_()
    {}

    ~TestRunnerTest()
    {
	for(TestCase* t : tests_)
	    delete t;

	tests_.clear();
    }

    void setUp()
    {
	addTest(new PassingTest());
	addTest(new FailingTest());
	addTest(new SkippedTest());
    }

    void run()
    {
	runner_.runTests(tests_);
    }

protected:
    void addTest(TestCase* test)
    {
	tests_.push_back(test);
    }

    TestRunner runner_;

private:
    std::vector<TestCase*> tests_;
};

struct TestRunnerReportsAFailureWhenATestFails : TestRunnerTest
{
    TestRunnerReportsAFailureWhenATestFails()
	: TestRunnerTest()
    {
	setName("TestRunnerReportsAFailureWhenATestFails");
    }

    void run()
    {
	TestRunnerTest::run();

	int errCount(runner_.getFailed());

	if(1 != errCount)
	    throw TestCase::TestFailed();
    }
};

struct TestRunnerReportsNoFailuresWhenAllTestsPass : TestRunnerTest
{
    TestRunnerReportsNoFailuresWhenAllTestsPass()
	: TestRunnerTest()
    {
	setName("TestRunnerReportsNoFailuresWhenAllTestsPass");
    }

    void setUp()
    {
	addTest(new PassingTest());
	addTest(new PassingTest());
	addTest(new PassingTest());
	addTest(new PassingTest());
	addTest(new PassingTest());
	addTest(new PassingTest());
    }

    void run()
    {
	TestRunnerTest::run();

	if(0 != runner_.getFailed())
	    throw TestCase::TestFailed();
    }

private:
};

struct TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip : TestRunnerTest
{
    TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip()
	: TestRunnerTest()
    {
	setName("TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip");
    }

    void setUp()
    {
	addTest(new PassingTest());
	addTest(new PassingTest());
	addTest(new SkippedTest());
	addTest(new PassingTest());
    }

    void run()
    {
	TestRunnerTest::run();

	if(0 != runner_.getFailed())
	    throw TestCase::TestFailed();
    }
};

void createTests(std::vector<TestCase*>& tests)
{
    tests.push_back(new PassingTestThrowsNoExceptions());
    tests.push_back(new FailingTestThrowsTestFailed());
    tests.push_back(new SkippedTestThrowsTestSkipped());
    tests.push_back(new TestRunnerReportsNoFailuresWhenAllTestsPass());
    tests.push_back(new TestRunnerReportsAFailureWhenATestFails());
    tests.push_back(new TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip());
}

void deleteTests(std::vector<TestCase*>& tests)
{
    for(TestCase* t : tests)
	delete t;

    tests.clear();
}

int main(int argc, const char* const argv[])
{
    std::vector<TestCase*> tests;

    createTests(tests);

    TestRunner runner;
    runner.runTests(tests);

    int errCount(runner.getFailed());

    deleteTests(tests);

    return errCount;
}
