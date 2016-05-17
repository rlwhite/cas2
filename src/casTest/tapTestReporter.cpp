#include "tapTestReporter.h"

TapTestReporter::TapTestReporter(std::ostream& outStream)
    : TestReporter(outStream)
{}

void TapTestReporter::printPlan(size_t testCount)
{
    outStream() << "1.."
		<< testCount << std::endl;
}

void TapTestReporter::printResult(TestResult::Result res,
				  size_t testNumber,
				  const std::string& testName)
{
    outStream() << resultToString(res)
		<< " " << testNumber
		<< " - " << testName
		<< (TestResult::Skipped == res ? " # SKIP" : "")
		<< std::endl;
}

void TapTestReporter::printSummary(size_t testsRan,
				size_t testsFailed,
				size_t testsSkipped)
{
    outStream() << "Tests ran: " << testsRan
		<< "\n\t" << "FAILED: " << testsFailed
		<< "\n\t" << "SKIPPED: " << testsSkipped
		<< std::endl;
}

std::string TapTestReporter::resultToString(TestResult::Result result)
{
    static const std::string resString[3] = {"ok", "not ok", "not ok"};

    return resString[result];
}
