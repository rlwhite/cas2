#ifndef TESTREPORTER_H
#define TESTREPORTER_H

#include "testResult.h"
#include <iostream>

struct TestReporter
{
    TestReporter(std::ostream& outStream = std::cout);

    std::ostream& printPlan(size_t testCount);
    std::ostream& printResult(TestResult::Result result,
			      size_t testNumber,
			      const std::string& testName);

private:

    std::ostream& out_;
};

#endif //TESTREPORTER_H
