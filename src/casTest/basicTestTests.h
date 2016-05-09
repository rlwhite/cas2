#ifndef BASICTESTTESTS_H
#define BASICTESTTESTS_H

#include "basicTests.h"

struct PassingTestThrowsNoExceptions : PassingTest
{
    PassingTestThrowsNoExceptions();

    void run();
};

struct FailingTestThrowsTestFailed : FailingTest
{
    FailingTestThrowsTestFailed();

    void run();
};

struct SkippedTestThrowsTestSkipped : SkippedTest
{
    SkippedTestThrowsTestSkipped();

    void run();
};


#endif //BASICTESTTESTS_H
