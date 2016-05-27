#ifndef TESTEXCEPTIONTESTS_H
#define TESTEXCEPTIONTESTS_H

#include "testCase.h"

struct TestExceptionContainsFileAndLineInfo : TestCase
{
    TestExceptionContainsFileAndLineInfo();
    
    void run();
};

struct ExpectTrueExceptionContainsAppropriateMessage : TestCase
{
    ExpectTrueExceptionContainsAppropriateMessage();
    
    void run();
};

struct ExpectFalseExceptionContainsAppropriateMessage : TestCase
{
    ExpectFalseExceptionContainsAppropriateMessage();
    
    void run();
};

struct ExpectEqualExceptionContainsAppropriateMessage : TestCase
{
    ExpectEqualExceptionContainsAppropriateMessage();
    
    void run();
};

struct ExpectNotEqualExceptionContainsAppropriateMessage : TestCase
{
    ExpectNotEqualExceptionContainsAppropriateMessage();

    void run();
};


struct UncaughtExceptionExceptionContainsAppropriateMessage : TestCase
{
    struct MyException{};

    UncaughtExceptionExceptionContainsAppropriateMessage();

    void run();

    void doesNotThrow() const;
};

struct UnexpectedExceptionContainsAppropriateMessage : TestCase
{
    UnexpectedExceptionContainsAppropriateMessage();

    void run();

private:
    void throwTestException() const;
};

#endif //TESTEXCEPTIONTESTS_H
