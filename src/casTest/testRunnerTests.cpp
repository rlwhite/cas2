#include "testRunnerTests.h"

#include "basicTests.h"
#include "testReporter.h"

struct MockTestReporter : TestReporter
{
    MockTestReporter()
	: TestReporter(std::cout)
    {}

    virtual ~MockTestReporter()
    {}

    void printPlan(size_t testCount)
    {}

    void printResult(TestResult::Result,
		     size_t,
		     const std::string&)
    {}

    void printSummary(size_t, size_t, size_t)
    {}

    std::string resultToString(TestResult::Result result)
    {
	static const char* resString[3] = {"Passed", "Failed", "Skipped"};

	return resString[result];
    }
};

TestRunnerTest::TestRunnerTest()
    : runner_(new MockTestReporter()),
      tests_()
{}

void TestRunnerTest::setUp()
{
    addTest(new PassingTest());
    addTest(new FailingTest());
    addTest(new SkippedTest());
}

void TestRunnerTest::tearDown()
{
    for(TestCase* t : tests_)
	delete t;
    
    tests_.clear();
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
    
    EXPECT_EQ(1, errCount);
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
    
    EXPECT_EQ(0, runner_.getFailed());
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
    
    EXPECT_EQ(0, runner_.getFailed());
}

TestRunnerReportsNoFailuresWhenAllTestsSkipped::
TestRunnerReportsNoFailuresWhenAllTestsSkipped()
    : TestRunnerTest()
{
    setName("TestRunnerReportsNoFailuresWhenAllTestsSkipped");
}

void TestRunnerReportsNoFailuresWhenAllTestsSkipped::setUp()
{
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
   addTest(new SkippedTest());
}

void TestRunnerReportsNoFailuresWhenAllTestsSkipped::run()
{
    TestRunnerTest::run();

    EXPECT_EQ(0, runner_.getFailed());
}

TestRunnerReportsSkipWhenTestIsSkipped::TestRunnerReportsSkipWhenTestIsSkipped()
    : TestRunnerTest()
{
    setName("TestRunnerReportsSkipWhenTestIsSkipped");
}

void TestRunnerReportsSkipWhenTestIsSkipped::setUp()
{
    addTest(new SkippedTest());
}

void TestRunnerReportsSkipWhenTestIsSkipped::run()
{
    TestRunnerTest::run();

    EXPECT_EQ(1, runner_.getSkipped());
}

TestRunnerReportsNoSkipsWhenAllTestsPass::
TestRunnerReportsNoSkipsWhenAllTestsPass()
    : TestRunnerTest()
{
    setName("TestRunnerReportsNoSkipsWhenAllTestsPass");
}

void TestRunnerReportsNoSkipsWhenAllTestsPass::setUp()
{
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
}

void TestRunnerReportsNoSkipsWhenAllTestsPass::run()
{
    TestRunnerTest::run();

    EXPECT_EQ(0, runner_.getSkipped());
}

TestRunnerReportsNoSkipsWhenAllTestsFail::
TestRunnerReportsNoSkipsWhenAllTestsFail()
    : TestRunnerTest()
{
    setName("TestRunnerReportsNoSkipsWhenAllTestsFail");
}

void TestRunnerReportsNoSkipsWhenAllTestsFail::setUp()
{
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
}

void TestRunnerReportsNoSkipsWhenAllTestsFail::run()
{
    TestRunnerTest::run();
    
    EXPECT_EQ(0, runner_.getSkipped());
}

TestRunnerReportsNoSkipsWhenAllTestsPassOrFail::
TestRunnerReportsNoSkipsWhenAllTestsPassOrFail()
    : TestRunnerTest()
{
    setName("TestRunnerReportsNoSkipsWhenAllTestsPassOrFail");
}

void TestRunnerReportsNoSkipsWhenAllTestsPassOrFail::setUp()
{
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new FailingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());
    addTest(new PassingTest());

}

void TestRunnerReportsNoSkipsWhenAllTestsPassOrFail::run()
{
    TestRunnerTest::run();
    
    EXPECT_EQ(0, runner_.getSkipped());
}
