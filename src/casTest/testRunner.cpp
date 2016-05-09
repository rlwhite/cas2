#include "testRunner.h"

#include "testCase.h"

#include <iostream>

TestRunner::TestRunner()
    : testNumber_(0),
      failed_(0),
      skipped_(0)
{}

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
    
    printSummary(failed_, skipped_);
}

void TestRunner::printHeader(size_t testCount) const
{
    std::cout << "Running " << testCount << " tests." << std::endl;
}

void TestRunner::printSummary(size_t errs, size_t skips) const
{
    std::cout << (0 == errs ? "All tests PASSED": "One or more tests FAILED")
	 << (0 == skips ? "" : " (One or more tests SKIPPED)")
	      << std::endl;
}

void TestRunner::printTestResult(const std::string& testName,
				 TestResult::Result result) const
{
	
    std::cout << "\t" << testNumber_ << ". " << testName
	      << ": " << TestResult::toString(result) << std::endl;
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

