#ifndef BASICTESTS_H
#define BASICTESTS_H

#include "testCase.h"

struct PassingTest : TestCase
{
    PassingTest();

    void run();

private:
};

struct FailingTest : TestCase
{
    FailingTest();

    void run();

private:
};

struct SkippedTest : TestCase
{
    SkippedTest();

    void run();

private:
};

#endif //BASICTESTS_H
