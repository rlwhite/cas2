#include "testRunner.h"

#include "testCase.h"
#include "testReporter.h"

#include <iostream>

TestRunner::TestRunner(TestReporter* reporter)
    : reporter_(reporter),
      testNumber_(0),
      failed_(0),
      skipped_(0)
{}

TestRunner::~TestRunner()
{
    delete reporter_;
}

size_t TestRunner::getFailed() const
{
    return failed_;
}

size_t TestRunner::getSkipped() const
{
    return skipped_;
}

void TestRunner::runTests(std::vector<TestCase*>& tests)
{
    printHeader(tests.size());
	
    testNumber_ = 0;

    for(TestCase* t : tests)
	printTestResult(t->name(),
			runTest(t));
    
    printSummary(tests.size(), failed_, skipped_);
}

void TestRunner::printHeader(size_t testCount) const
{
    reporter_->printPlan(testCount);
}

void TestRunner::printSummary(size_t testCount,
			      size_t errs,
			      size_t skips) const
{
    reporter_->printSummary(testCount,
			    errs,
			    skips);
}

void TestRunner::printTestResult(const std::string& testName,
				 TestResult::Result result) const
{
    reporter_->printResult(result,
			   testNumber_,
			   testName);
}

TestResult::Result TestRunner::runTest(TestCase* test)
{
    ++testNumber_;
    test->setUp();

    TestResult::Result res(tryTest(test));

    test->tearDown();

    return res;
}

TestResult::Result TestRunner::tryTest(TestCase* test)
{
    TestResult::Result res(TestResult::Passed);

    try
    {
	test->run();
    }
    catch(const TestCase::TestFailed&)
    {
	++failed_;
	res = TestResult::Failed;
    }
    catch(const TestCase::TestSkipped&)
    {
	++skipped_;
	res = TestResult::Skipped;
    }

    return res;
}

