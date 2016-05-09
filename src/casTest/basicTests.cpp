#include "basicTests.h"

PassingTest::PassingTest()
{
    setName("PassingTest");
}

void PassingTest::run()
{}

FailingTest::FailingTest()
{
    setName("FailingTest");
}

void FailingTest::run()
{
    throw TestFailed();
}

SkippedTest::SkippedTest()
{
    setName("SkippedTest");
}

void SkippedTest::run()
{
    throw TestSkipped();
}

