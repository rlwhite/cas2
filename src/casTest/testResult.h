#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <string>

struct TestResult
{
    enum Result
    {
	Passed,
	Failed,
	Skipped
    };
};

#endif //TESTRESULT_H
