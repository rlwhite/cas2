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
