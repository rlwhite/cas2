#ifndef TAPTESTREPORTERTESTS_H
#define TAPTESTREPORTERTESTS_H

#include "testCase.h"

#include <sstream>

struct TestReporter;

struct TestReporterTest : TestCase
{
    TestReporterTest();

    void setUp();
    void tearDown();

protected:
    std::stringstream outStream_;
    TestReporter* reporter_;
};

struct TestReporterPrintsTestPlan : TestReporterTest
{
    TestReporterPrintsTestPlan();
    
    void run();
};

struct TestReporterPrintsOKForPassedTest : TestReporterTest
{
    TestReporterPrintsOKForPassedTest();
    
    void run();
};

struct TestReporterPrintsNOTOKForFailedTest : TestReporterTest
{
    TestReporterPrintsNOTOKForFailedTest();

    void run();
};

struct TestReporterPrintsSKIPPEDForSkippedTest : TestReporterTest
{
    TestReporterPrintsSKIPPEDForSkippedTest();

    void run();
};

struct TestReporterPrintsTestSummary : TestReporterTest
{
    TestReporterPrintsTestSummary();

    void run();
};

#endif //TESTREPORTERTESTS_H
