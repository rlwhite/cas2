#ifndef TESTREPORTERTESTS_H
#define TESTREPORTERTESTS_H

#include "testCase.h"

#include <sstream>

struct TestReporter;

struct TestReporterTest : TestCase
{
    TestReporterTest();
    virtual ~TestReporterTest();

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

#endif //TESTREPORTERTESTS_H
