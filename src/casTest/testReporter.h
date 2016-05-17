#ifndef TESTREPORTER_H
#define TESTREPORTER_H

#include "testResult.h"
#include <iostream>

struct TestReporter
{
    TestReporter(std::ostream& outStream = std::cout);
    virtual ~TestReporter();

    virtual void printPlan(size_t testCount) = 0;

    virtual void printResult(TestResult::Result result,
			     size_t testNumber,
			     const std::string& testName) = 0;

    virtual void printSummary(size_t testsRan,
			      size_t testsFailed,
			      size_t testsSkipped) = 0;

    virtual std::string resultToString(TestResult::Result result) = 0;

protected:
    std::ostream& outStream();

private:
    std::ostream& out_;
};

#endif //TESTREPORTER_H
