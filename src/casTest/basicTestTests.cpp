#include "basicTestTests.h"
#include "testCase.h"


PassingTestThrowsNoExceptions::PassingTestThrowsNoExceptions()
{
    setName("PassingTestThrowsNoExceptions");
}

void PassingTestThrowsNoExceptions::run()
{
    EXPECT_NOTHROW(PassingTest::run());
}

FailingTestThrowsTestFailed::FailingTestThrowsTestFailed()
{
    setName("FailingTestThrowsTestFailed");
}

void FailingTestThrowsTestFailed::run()
{
    EXPECT_THROWS(TestCase::TestFailed, FailingTest::run());
}

SkippedTestThrowsTestSkipped::SkippedTestThrowsTestSkipped()
{
    setName("SkippedTestThrowsTestSkipped");
}

void SkippedTestThrowsTestSkipped::run()
{
    EXPECT_THROWS(TestCase::TestSkipped, SkippedTest::run());
}
