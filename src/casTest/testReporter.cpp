#include "testReporter.h"

#include <sstream>

TestReporter::TestReporter(std::ostream& outStream)
    : out_(outStream)
{}

std::ostream& TestReporter::printPlan(size_t testCount)
{
    out_ << "1.."
	 << testCount << std::endl;

    return out_;
}

std::ostream& TestReporter::printResult(TestResult::Result res,
					size_t testNumber,
					const std::string& testName)
{
    out_ << TestResult::toString(res)
	 << " " << testNumber
	 << " - " << testName
	 << std::endl;
    
    return out_;
}



