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
    
    if("1..10\n" != outStream_.str())
	throw TestCase::TestFailed();
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

    if("ok 1 - MyFakeTest\n" != outStream_.str())
	throw TestCase::TestFailed();
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

    if("not ok 2 - MyFakeFailedTest\n" != outStream_.str())
	throw TestCase::TestFailed();
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

    if("not ok 3 - MyFakeSkippedTest # SKIP\n" != outStream_.str())
	throw TestCase::TestFailed();
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

    if("Tests ran: 10\n\tFAILED: 1\n\tSKIPPED: 2\n" !=
       outStream_.str())
	throw TestCase::TestFailed();
}
