#ifndef TESTREPORTER_H
#define TESTREPORTER_H

#include "testResult.h"
#include <iostream>

struct TestReporter
{
    TestReporter(std::ostream& outStream = std::cout);
    virtual ~TestReporter();

    void printPlan(size_t testCount);

    void printResult(TestResult::Result result,
			      size_t testNumber,
			      const std::string& testName);

    void printSummary(size_t testsRan,
		      size_t testsFailed,
		      size_t testsSkipped);

private:

    std::ostream& out_;
};

#endif //TESTREPORTER_H
