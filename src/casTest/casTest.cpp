#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#define print(msg) cout << msg << endl
#define printResult(errs) cout <<                                 \
                                 (0 == errs ? "All tests PASSED": \
                                  "One or more tests FAILED") << endl

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
    {

    }

private:
};

struct PassingTestTest : PassingTest
{
    PassingTestTest()
    {
	setName("PassingTestTest");
    }

    void run()
    {
	try
	{
	    PassingTest::run();
	}
	catch(const TestCase::TestFailed& x)
	{
	    throw;
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

struct FailingTestTest : FailingTest
{
    FailingTestTest()
    {
	setName("FailingTestTest");
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

struct SkippedTestTest : SkippedTest
{
    SkippedTestTest()
    {
	setName("SkippedTestTest");
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

int runTests(std::vector<TestCase*>& tests)
{
    print("Running " << tests.size() << " tests.");
    int errCount(0);

    for(size_t t(0); t < tests.size(); ++t)
    {
	int oldErrCount(errCount);

	try
	{
	    tests[t]->run();
	}
	catch(const TestCase::TestFailed& x)
	{
	    ++errCount;
	}
	
	print("\t" << (t + 1) << ": " << tests[t]->name() << ": " <<
	      (oldErrCount == errCount ? "OK" : "NOT OK"));
    }
    
    return errCount;
}

void createTests(std::vector<TestCase*>& tests)
{
    tests.push_back(new PassingTestTest());
    tests.push_back(new FailingTestTest());
    tests.push_back(new SkippedTestTest());
}

void deleteTests(std::vector<TestCase*>& tests)
{
    for(size_t t(0); t < tests.size(); ++t)
	delete tests[t];

    tests.clear();
}

int main(int argc, const char* const argv[])
{
    std::vector<TestCase*> tests;

    createTests(tests);

    int errCount(runTests(tests));

    deleteTests(tests);

    printResult(errCount);

    return errCount;
}
