#include "testRunnerTests.h"

#include "basicTests.h"

TestRunnerTest::TestRunnerTest()
    : runner_(),
      tests_()
{}

TestRunnerTest::~TestRunnerTest()
{
    for(TestCase* t : tests_)
	delete t;
    
    tests_.clear();
}

void TestRunnerTest::setUp()
{
    addTest(new PassingTest());
    addTest(new FailingTest());
    addTest(new SkippedTest());
}

void TestRunnerTest::run()
{
    runner_.runTests(tests_);
}

void TestRunnerTest::addTest(TestCase* test)
{
    tests_.push_back(test);
}

TestRunnerReportsAFailureWhenATestFails::
TestRunnerReportsAFailureWhenATestFails()
    : TestRunnerTest()
{
    setName("TestRunnerReportsAFailureWhenATestFails");
}

void TestRunnerReportsAFailureWhenATestFails::run()
{
    TestRunnerTest::run();
    
    int errCount(runner_.getFailed());
    
    if(1 != errCount)
	throw TestCase::TestFailed();
}

TestRunnerReportsNoFailuresWhenAllTestsPass::
TestRunnerReportsNoFailuresWhenAllTestsPass()
    : TestRunnerTest()
{
    setName("TestRunnerReportsNoFailuresWhenAllTestsPass");
}

void TestRunnerReportsNoFailuresWhenAllTestsPass::setUp()
{
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
}

void TestRunnerReportsNoFailuresWhenAllTestsPass::run()
{
    TestRunnerTest::run();
    
    if(0 != runner_.getFailed())
	throw TestCase::TestFailed();
}

TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip::
TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip()
    : TestRunnerTest()
{
    setName("TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip");
}

void TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip::setUp()
{
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new SkippedTest());
    addTest(new PassingTest());
}

void TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip::run()
{
    TestRunnerTest::run();
    
    if(0 != runner_.getFailed())
	throw TestCase::TestFailed();
}

