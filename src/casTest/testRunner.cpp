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
	runTest(t);
    
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
				 const std::string& result) const
{
	
    std::cout << "\t" << testNumber_ << ". " << testName
	      << ": " << result << std::endl;
}

void TestRunner::runTest(TestCase* test)
{
    int previousFailed(failed_);
    int previousSkipped(skipped_);
	
    ++testNumber_;
    test->setUp();
    tryTest(test);
    test->tearDown();

    printTestResult(test->name(),
	previousSkipped == skipped_ ? 
	(previousFailed == failed_ ? "OK" : "NOT OK") : "SKIPPED");
}

void TestRunner::tryTest(TestCase* test)
{
    try
    {
	test->run();
    }
    catch(const TestCase::TestFailed&)
    {
	++failed_;
    }
    catch(const TestCase::TestSkipped&)
    {
	++skipped_;
    }
}

