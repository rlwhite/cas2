#include "basicTestTests.h"

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
	throw TestCase::TestFailed();
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
    
    if(!success)
	throw TestCase::TestFailed();
}

SkippedTestThrowsTestSkipped::SkippedTestThrowsTestSkipped()
{
    setName("SkippedTestThrowsTestSkipped");
}

void SkippedTestThrowsTestSkipped::run()
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
