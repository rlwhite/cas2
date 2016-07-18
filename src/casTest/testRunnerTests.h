#ifndef TESTRUNNERTESTS
#define TESTRUNNERTESTS

#include "testCase.h"
#include "testRunner.h"

#include <vector>

struct TestRunnerTest : TestCase
{
    TestRunnerTest();
    ~TestRunnerTest();

    void setUp();
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

#endif //TESTRUNNERTESTS
