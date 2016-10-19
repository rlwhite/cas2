#ifndef TESTRUNNERTESTS
#define TESTRUNNERTESTS

#include "testCase.h"
#include "testRunner.h"

#include <vector>

struct TestRunnerTest : TestCase
{
    TestRunnerTest();

    void setUp();
    void tearDown();
    void run();

protected:
    void addTest(TestCase* test);

    TestRunner runner_;

private:
    std::vector<TestCase*> tests_;
};

struct TestRunnerReportsAFailureWhenATestFails : TestRunnerTest
{
    TestRunnerReportsAFailureWhenATestFails();

    void run();
};

struct TestRunnerReportsNoFailuresWhenAllTestsPass : TestRunnerTest
{
    TestRunnerReportsNoFailuresWhenAllTestsPass();

    void setUp();
    void run();
};

struct TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip : TestRunnerTest
{
    TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip();

    void setUp();
    void run();
};

struct TestRunnerReportsNoFailuresWhenAllTestsSkipped : TestRunnerTest
{
    TestRunnerReportsNoFailuresWhenAllTestsSkipped();

    void setUp();
    void run();
};

struct TestRunnerReportsSkipWhenTestIsSkipped : TestRunnerTest
{
    TestRunnerReportsSkipWhenTestIsSkipped();

    void setUp();
    void run();
};

struct TestRunnerReportsNoSkipsWhenAllTestsPass : TestRunnerTest
{
    TestRunnerReportsNoSkipsWhenAllTestsPass();
    
    void setUp();
    void run();
};

struct TestRunnerReportsNoSkipsWhenAllTestsFail : TestRunnerTest
{
    TestRunnerReportsNoSkipsWhenAllTestsFail();
    
    void setUp();
    void run();
};

struct TestRunnerReportsNoSkipsWhenAllTestsPassOrFail : TestRunnerTest
{
    TestRunnerReportsNoSkipsWhenAllTestsPassOrFail();
    
    void setUp();
    void run();
};

#endif //TESTRUNNERTESTS
