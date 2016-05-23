#include "basicTestTests.h"
#include "testCase.h"


PassingTestThrowsNoExceptions::PassingTestThrowsNoExceptions()
{
    setName("PassingTestThrowsNoExceptions");
}

void PassingTestThrowsNoExceptions::run()
{
    try
    {
	PassingTest::run();
    }
    catch(...)
    {
	throw TestCase::TestFailed(__FILE__, __LINE__);
    }
}

FailingTestThrowsTestFailed::FailingTestThrowsTestFailed()
{
    setName("FailingTestThrowsTestFailed");
}

void FailingTestThrowsTestFailed::run()
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
    
    EXPECT_TRUE(success);
}

SkippedTestThrowsTestSkipped::SkippedTestThrowsTestSkipped()
{
    setName("SkippedTestThrowsTestSkipped");
}

void SkippedTestThrowsTestSkipped::run()
{
    EXPECT_THROWS(TestCase::TestSkipped, SkippedTest::run());
}
