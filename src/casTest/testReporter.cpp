#include "testReporter.h"

TestReporter::TestReporter(std::ostream& outStream)
    : out_(outStream)
{}

TestReporter::~TestReporter()
{}

std::ostream& TestReporter::outStream()
{
    return out_;
}
