#ifndef TESTRESULTTESTS_H
#define TESTRESULTTESTS_H

#include "testCase.h"
#include "testResult.h"

struct TestResultToStringReturnsPassedForPassed : TestCase
{
    TestResultToStringReturnsPassedForPassed();

    void run();
};

struct TestResultToStringReturnsFailedForFailed : TestCase
{
    TestResultToStringReturnsFailedForFailed();

    void run();
};

struct TestResultToStringReturnsSkippedForSkipped : TestCase
{
    TestResultToStringReturnsSkippedForSkipped();

    void run();
};

#endif //TESTRESULTTESTS_H
