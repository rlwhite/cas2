#include "tapTestReporterTests.h"

#include "tapTestReporter.h"
#include "testResult.h"

TestReporterTest::TestReporterTest()
    : outStream_(),
      reporter_(0)
{
    reporter_ = new TapTestReporter(outStream_);
}

TestReporterTest::~TestReporterTest()
{
    delete reporter_;
}

TestReporterPrintsTestPlan::TestReporterPrintsTestPlan()
    : TestReporterTest()
{
    setName("TestReporterPrintsTestPlan");
}

void TestReporterPrintsTestPlan::run()
{
    reporter_->printPlan(10);
    
    EXPECT_TRUE("1..10\n" == outStream_.str());
}

TestReporterPrintsOKForPassedTest::TestReporterPrintsOKForPassedTest()
    : TestReporterTest()
{
    setName("TestReporterPrintsOKForPassedTest");
}

void TestReporterPrintsOKForPassedTest::run()
{
    reporter_->printResult(TestResult::Passed,
			   1,
			   "MyFakeTest");

    EXPECT_TRUE("ok 1 - MyFakeTest\n"== outStream_.str());
}

TestReporterPrintsNOTOKForFailedTest::TestReporterPrintsNOTOKForFailedTest()
    : TestReporterTest()
{
    setName("TestReporterPrintsNOTOKForFailedTest");
}

void TestReporterPrintsNOTOKForFailedTest::run()
{
    reporter_->printResult(TestResult::Failed,
			   2,
			   "MyFakeFailedTest");

    EXPECT_TRUE("not ok 2 - MyFakeFailedTest\n" == outStream_.str());
}

TestReporterPrintsSKIPPEDForSkippedTest::
TestReporterPrintsSKIPPEDForSkippedTest()
    : TestReporterTest()
{
    setName("TestReporterPrintsSKIPPEDForSkippedTest");
}

void TestReporterPrintsSKIPPEDForSkippedTest::run()
{
    reporter_->printResult(TestResult::Skipped,
			   3,
			   "MyFakeSkippedTest");

    EXPECT_TRUE("not ok 3 - MyFakeSkippedTest # SKIP\n" == outStream_.str());
}

TestReporterPrintsTestSummary::TestReporterPrintsTestSummary()
    : TestReporterTest()
{
    setName("TestReporterPrintsTestSummary");
}

void TestReporterPrintsTestSummary::run()
{
    reporter_->printSummary(10,
			    1,
			    2);

    EXPECT_TRUE("Tests ran: 10\n\tFAILED: 1\n\tSKIPPED: 2\n" ==
		outStream_.str());
}
