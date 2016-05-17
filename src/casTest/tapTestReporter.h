#ifndef TAPTESTREPORTER_H
#define TAPTESTREPORTER_H

#include "testReporter.h"

#include <iostream>
struct TapTestReporter : TestReporter
{
    TapTestReporter(std::ostream& outStream = std::cout);
    
    void printPlan(size_t testCount);

    void printResult(TestResult::Result result,
		     size_t testNumber,
		     const std::string& testName);

    void printSummary(size_t testsRan,
		      size_t testsFailed,
		      size_t testsSkipped);

    std::string resultToString(TestResult::Result result);
};

#endif //TAPTESTREPORTER_H
