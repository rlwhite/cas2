#include "testExceptionTests.h"

#include <cstring>

TestExceptionContainsFileAndLineInfo::TestExceptionContainsFileAndLineInfo()
    : TestCase()
{
    setName("TestExceptionContainsFileAndLineInfo");
}

void TestExceptionContainsFileAndLineInfo::run()
{
    static const char* const testSource(__FILE__);
    static const size_t line(__LINE__);

    TestCase::TestFailed testException(testSource,
				       line,
				       "TestFailed exception");

    EXPECT_TRUE(0 == strcmp(testSource, testException.src_));
    EXPECT_TRUE(line == testException.line_);
}

ExpectTrueExceptionContainsAppropriateMessage::
ExpectTrueExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectTrueExceptionContainsAppropriateMessage");
}

void ExpectTrueExceptionContainsAppropriateMessage::run()
{
    try
    {
	EXPECT_TRUE(0 == 1);
    }
    catch(const TestCase::TestFailed& x)
    {
	EXPECT_TRUE("0 == 1 is not true." == x.what());
    }
}

ExpectFalseExceptionContainsAppropriateMessage::
ExpectFalseExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectFalseExceptionContainsAppropriateMessage");
}

void ExpectFalseExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_FALSE(0 == 0);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_TRUE("0 == 0 is not false." == x.what());
    }

    EXPECT_TRUE(success);
}

ExpectEqualExceptionContainsAppropriateMessage::
ExpectEqualExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectEqualExceptionContainsAppropriateMessage");
}

void ExpectEqualExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_EQ(0, 1);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_EQ("0 != 1", x.what());
    }

    EXPECT_TRUE(success);
}

ExpectNotEqualExceptionContainsAppropriateMessage::
ExpectNotEqualExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectNotEqualExceptionContainsAppropriateMessage");
}

void ExpectNotEqualExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_NE(0, 0);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_EQ("0 == 0", x.what());
    }

    EXPECT_TRUE(success);
}

ExpectLTExceptionContainsAppropriateMessage::
ExpectLTExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectLTExceptionContainsAppropriateMessage");
}

void ExpectLTExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_LT(0, 0);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_EQ("0 is not < 0", x.what());
    }

    EXPECT_TRUE(success);
}

ExpectLEExceptionContainsAppropriateMessage::
ExpectLEExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectLEExceptionContainsAppropriateMessage");
}

void ExpectLEExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_LE(1, 0);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_EQ("1 is not <= 0", x.what());
    }

    EXPECT_TRUE(success);
}

ExpectGTExceptionContainsAppropriateMessage::
ExpectGTExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectGTExceptionContainsAppropriateMessage");
}

void ExpectGTExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_GT(0, 0);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_EQ("0 is not > 0", x.what());
    }

    EXPECT_TRUE(success);
}

ExpectGEExceptionContainsAppropriateMessage::
ExpectGEExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("ExpectGEExceptionContainsAppropriateMessage");
}

void ExpectGEExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_GE(0, 1);
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_EQ("0 is not >= 1", x.what());
    }

    EXPECT_TRUE(success);
}

UnexpectedExceptionContainsAppropriateMessage::
UnexpectedExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("UnexpectedExceptionContainsAppropriateMessage");
}

void UnexpectedExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_NOTHROW(throwTestException());
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_TRUE("Caught unexpected exception." == x.what());
    }

    EXPECT_TRUE(success);
}

void UnexpectedExceptionContainsAppropriateMessage::throwTestException() const
{
    EXPECT_TRUE("Forced exception" == "Exception forced");
}

UncaughtExceptionExceptionContainsAppropriateMessage::
UncaughtExceptionExceptionContainsAppropriateMessage()
    : TestCase()
{
    setName("UncaughtExceptionExceptionContainsAppropriateMessage");
}

void UncaughtExceptionExceptionContainsAppropriateMessage::run()
{
    bool success(false);

    try
    {
	EXPECT_THROWS(MyException, doesNotThrow());
    }
    catch(const TestCase::TestFailed& x)
    {
	success = true;
	EXPECT_TRUE("MyException not thrown." == x.what());
    }

    EXPECT_TRUE(success);
}

void UncaughtExceptionExceptionContainsAppropriateMessage::doesNotThrow() const
{}

