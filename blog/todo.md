**TODO**
--------
* TestRunner tests:

>* <del>PassingTestThrowsNoExceptions</del>
>* <del>FailingTestThrowsTestFailed</del>
>* <del>SkippedTestThrowsTestSkipped</del>
>* <del>TestRunnerReportsNoFailuresWhenAllTestsPass</del>
>* TestRunnerReportsNoFailuresWhenAllTestsSkipped
>* TestRunnerReportsSkipWhenTestIsSkipped
>* TestRunnerReportsNoSkipsWhenAllTestsPass
>* TestRunnerReportsNoSkipsWhenAllTestsFail
>* <del>TestRunnerReportsNoFailuresWhenAllTestsPassOrSkip</del>
>* TestRunnerReportsNoSkipsWhenAllTestsPassOrFail

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
  -- Create an error message factory that translates exception objects into
     error messages
* Implement test construction macros

* Rework the make system to be fully independent
* Consider whether or not *casTest* should be built into a single executable tool (rather than multiple tools).
* Consider replace *out_* member of *TestReporter* with something else.
