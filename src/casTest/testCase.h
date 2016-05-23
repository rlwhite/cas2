#ifndef TESTCASE_H
#define TESTCASE_H

#include <string>

struct TestCase
{
    struct TestFailed
    {
	TestFailed(const char* const file,
		   size_t line);

	const char* const src_;
	size_t line_;
    };

    struct TestSkipped
    {};

    virtual ~TestCase();

    virtual void setUp();

    virtual void tearDown();

    virtual void run() = 0;

    const std::string& name() const;

protected:
    void setName(const std::string& name);

private:
    std::string name_;
};

#define EXPECT_TRUE(exp)					\
    if(!(exp)) throw TestCase::TestFailed(__FILE__, __LINE__)

#define EXPECT_FALSE(exp)					\
    if((exp)) throw TestCase::TestFailed(__FILE__, __LINE__)

#define EXPECT_THROWS(except, func)                                  \
    bool success(false);					     \
								     \
    try								     \
    {								     \
        func;							     \
    }								     \
    catch(const except& x)					     \
    {								     \
        success = true;						     \
    }								     \
    								     \
    if(!success) throw TestCase::TestFailed(__FILE__, __LINE__)      \

#endif //TESTCASE_H
