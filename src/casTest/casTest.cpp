
#include "testCase.h"
#include "basicTests.h"
#include "basicTestTests.h"
#include "tapTestReporter.h"
#include "testRunner.h"
#include "testRunnerTests.h"
#include "testReporterTests.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define print(msg) cout << msg << endl

void createTests(std::vector<TestCase*>& tests)
{
    tests.push_back(new PassingTestThrowsNoExceptions());
    tests.push_back(new FailingTestThrowsTestFailed());
    tests.push_back(new SkippedTestThrowsTestSkipped());
    tests.push_back(new TestRunnerReportsNoFailuresWhenAllTestsPass());
    tests.push_back(new TestRunnerReportsAFailureWhenATestFails());
    tests.push_back(new TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip());
    tests.push_back(new TestReporterPrintsTestPlan());
    tests.push_back(new TestReporterPrintsOKForPassedTest());
    tests.push_back(new TestReporterPrintsNOTOKForFailedTest());
    tests.push_back(new TestReporterPrintsSKIPPEDForSkippedTest());
    tests.push_back(new TestReporterPrintsTestSummary());
}

void deleteTests(std::vector<TestCase*>& tests)
{
    for(TestCase* t : tests)
	delete t;

    tests.clear();
}

int main(int argc, const char* const argv[])
{
    std::vector<TestCase*> tests;

    createTests(tests);

    TestRunner runner(new TapTestReporter());
    runner.runTests(tests);

    int errCount(runner.getFailed());

    deleteTests(tests);

    return errCount;
}
