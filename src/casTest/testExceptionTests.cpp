#include "testExceptionTests.h"

#include <cstring>

TestExceptionContainsFileAndLineInfo::TestExceptionContainsFileAndLineInfo()
    : TestCase()
{
    setName("TestExceptionContainsFileAndLineInfo");
}

void TestExceptionContainsFileAndLineInfo::run()
{
    static const char* const testSource("testSourceFile");

    TestCase::TestFailed testException(testSource, 22);

    EXPECT_TRUE(0 == strcmp("testSourceFile", testException.src_));
    EXPECT_TRUE(22 == testException.line_);
}
