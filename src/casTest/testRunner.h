#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <cstddef>
#include <string>
#include <vector>

struct TestCase;

struct TestRunner
{
    TestRunner();

    size_t getFailed() const;
    size_t getSkipped() const;

    void runTests(std::vector<TestCase*>& tests);

private:
    void printHeader(size_t testCount) const;
    void printSummary(size_t errs, size_t skips) const;
    void printTestResult(const std::string& testName,
			 const std::string& result) const;

    void runTest(TestCase* test);
    void tryTest(TestCase* test);

    size_t testNumber_;
    size_t failed_;
    size_t skipped_;
};

#endif //TESTRUNNER_H
