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
    throw TestFailed(__FILE__, __LINE__);
}

SkippedTest::SkippedTest()
{
    setName("SkippedTest");
}

void SkippedTest::run()
{
    throw TestSkipped();
}

