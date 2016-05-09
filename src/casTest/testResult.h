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

    static std::string toString(Result result);
};

#endif //TESTRESULT_H
