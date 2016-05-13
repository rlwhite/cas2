#include "testReporter.h"

TestReporter::TestReporter(std::ostream& outStream)
    : out_(outStream)
{}

TestReporter::~TestReporter()
{}

void TestReporter::printPlan(size_t testCount)
{
    out_ << "1.."
	 << testCount << std::endl;
}

void TestReporter::printResult(TestResult::Result res,
			       size_t testNumber,
			       const std::string& testName)
{
    out_ << TestResult::toString(res)
	 << " " << testNumber
	 << " - " << testName
	 << std::endl;
}

void TestReporter::printSummary(size_t testsRan,
				size_t testsFailed,
				size_t testsSkipped)
{
    out_ << "Tests ran: " << testsRan
	 << "\n\t" << "FAILED: " << testsFailed
	 << "\n\t" << "SKIPPED: " << testsSkipped
	 << std::endl;
}
