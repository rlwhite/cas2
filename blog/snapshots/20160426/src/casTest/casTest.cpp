#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#define print(msg) cout << msg << endl
#define printResult(errs, skips) cout <<				\
    (0 == errs ? "All tests PASSED":					\
                 "One or more tests FAILED") << 			\
    (0 == skips ? "" : " (One or more tests SKIPPED)") << endl

struct TestCase
{
    struct TestFailed
    {};

    struct TestSkipped
    {};

    virtual ~TestCase()
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
	: failed_(0),
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
	size_t testNumber(0);
	
	for(TestCase* t : tests)
	{
	    int previousFailed(failed_);
	    int previousSkipped(skipped_);
	    
	    tryTest(t);
	    
	    ++testNumber;
	    print("\t" << testNumber << ". " << t->name() << ": " <<
		  (previousSkipped == skipped_ ? 
		   (previousFailed == failed_ ? "OK" : "NOT OK") : "SKIPPED"));
	}
    
	printResult(failed_, skipped_);
    }

private:
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
	addTest(new PassingTest());
	addTest(new FailingTest());
	addTest(new SkippedTest());

	TestRunnerTest::run();

	int errCount(runner_.getFailed());

	if(1 != errCount)
	    throw TestCase::TestFailed();
    }
};

struct TestRunnerReportsNoFailuresWhenAllTestsPass : TestRunnerTest
{


private:
};

struct TestRunnerReportsNoFailuresWhenATestIsSkipped : TestRunnerTest
{

};

void createTests(std::vector<TestCase*>& tests)
{
    tests.push_back(new PassingTestThrowsNoExceptions());
    tests.push_back(new FailingTestThrowsTestFailed());
    tests.push_back(new SkippedTestThrowsTestSkipped());
    //tests.push_back(new TestRunnerReportsNoFailuresWhenAllTestsPass());
    tests.push_back(new TestRunnerReportsAFailureWhenATestFails());
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
