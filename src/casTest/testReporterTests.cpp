#include "testReporterTests.h"

#include "testReporter.h"

#include <sstream>

TestReporterPrintsTestPlan::TestReporterPrintsTestPlan()
{
    setName("TestReporterPrintsTestPlan");
}

void TestReporterPrintsTestPlan::run()
{
    std::stringstream outStream;
    TestReporter reporter(outStream);
    
    reporter.printPlan(10);

    const std::string& output(outStream.str());

    if("1..10\n" != output)
	throw TestCase::TestFailed();
}
