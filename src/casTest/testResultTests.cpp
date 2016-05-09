#include "testResultTests.h"

#include <string>

TestResultToStringReturnsPassedForPassed::
TestResultToStringReturnsPassedForPassed()
{
    setName("TestResultToStringReturnsPassedForPassed");
}

void TestResultToStringReturnsPassedForPassed::run()
{
    if("OK" != TestResult::toString(TestResult::Passed))
	throw TestCase::TestFailed();
}

TestResultToStringReturnsFailedForFailed::
TestResultToStringReturnsFailedForFailed()
{
    setName("TestResultToStringReturnsFailedForFailed");
}

void TestResultToStringReturnsFailedForFailed::run()
{
    if("NOT OK" != TestResult::toString(TestResult::Failed))
	throw TestCase::TestFailed();
}

TestResultToStringReturnsSkippedForSkipped::
TestResultToStringReturnsSkippedForSkipped()
{
    setName("TestResultToStringReturnsSkippedForSkipped");
}

void TestResultToStringReturnsSkippedForSkipped::run()
{
    if("SKIPPED" != TestResult::toString(TestResult::Skipped))
	throw TestCase::TestFailed();
}
