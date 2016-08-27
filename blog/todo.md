**TODO**
--------
* TestRunner tests:

>* <del>PassingTestThrowsNoExceptions</del>
>* <del>FailingTestThrowsTestFailed</del>
>* <del>SkippedTestThrowsTestSkipped</del>
>* <del>TestRunnerReportsNoFailuresWhenAllTestsPass</del>
>* <del>TestRunnerReportsNoFailuresWhenAllTestsSkipped</del>
>* <del>TestRunnerReportsSkipWhenTestIsSkipped</del>
>* <del>TestRunnerReportsNoSkipsWhenAllTestsPass</del>
>* <del>TestRunnerReportsNoSkipsWhenAllTestsFail</del>
>* <del>TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip</del>
>* <del>TestRunnerReportsNoSkipsWhenAllTestsPassOrFail</del>

* TestReporter tests:
>* <del>TestReporterPrintsOKForPassedTest</del>
>* <del>TestReporterPrintsTestPlan</del>
>* <del>TestReporterPrintsNOTOKForFailedTest</del>
>* <del>TestReporterPrintsSKIPPEDForSkippedTest</del>
>* <del>TestReporterPrintsTestSummary</del>

* <del>Split the code into multiple files</del>
* <del>Refactor *TestRunner::runTest()*.  Should *tryTest()* return the test result (PASS, FAIL, SKIP) ?</del>
* <del>Create test logger/reporter.  How should we format the report?  Use TAP-style output?</del>

* Implement various assert macros for test writers
>* <del>EXPECT_TRUE</del>
>* <del>EXPECT_FALSE</del>
>* <del>EXPECT_THROWS</del>
>* <del>EXPECT_NOTHROW</del>
>* <del>EXPECT_EQ</del>
>* <del>EXPECT_NE<del>
>* <del>EXPECT_LT</del>
>* <del>EXPECT_LE</del>
>* <del>EXPECT_GT</del>
>* <del>EXPECT_GE<del>

>* <del>Create an error message factory that translates exception objects into
error messages</del>

* Implement test construction macros

* Rework the make system to be fully independent
* Consider whether or not *casTest* should be built into a single executable tool (rather than multiple tools).
* Consider replace *out_* member of *TestReporter* with something else.

* Create a library loader/plugin class to wrap the dynamic library routines we need for the plugins.
>* *void createTests(std::vector<TestCase*>&)*
>* *void deleteTests(std::vector<TestCase*>&)*
>* *TestReporter\* createTestReporter()*
>* *void deleteTestReporter(TestReporter\*)*

* Move all self-tests to a shared library so that the self test functions like any other test to be executed.


