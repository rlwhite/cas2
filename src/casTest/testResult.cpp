#include "testResult.h"

std::string TestResult::toString(TestResult::Result result)
{
    std::string res("Undefined");

    switch(result)
    {
        case Passed:
	     res = "OK";
	     break;

        case Failed:
	    res = "NOT OK";
	    break;

        case Skipped:
	    res = "SKIPPED";
	    break;

        default:
	    ;
    }

    return res;
}
