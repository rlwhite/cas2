#ifndef TESTCASE_H
#define TESTCASE_H

#include <string>

#include <iostream>
struct TestCase
{
    struct TestFailed
    {
        TestFailed(const char* const file,
                   size_t line,
                   const char* msg);

        ~TestFailed() throw();

        const char* what() const;

        const char* const src_;
        const size_t line_;
        const char* msg_;
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

#define EXPECT_TRUE(exp)                                            \
        if(!(exp)) throw TestCase::TestFailed(__FILE__,             \
                                              __LINE__,             \
                                              #exp " is not true.")

#define EXPECT_FALSE(exp)                           \
    if((exp)) throw TestCase::TestFailed(__FILE__,  \
                                         __LINE__,  \
                                         #exp " is not false.")

#define EXPECT_EQ(v1, v2)				     \
    if(v1 != v2) throw TestCase::TestFailed(__FILE__,        \
				            __LINE__,        \
                                            #v1 " != " #v2)

#define EXPECT_NE(v1, v2)				     \
    if(v1 == v2) throw TestCase::TestFailed(__FILE__,        \
				            __LINE__,        \
                                            #v1 " == " #v2)

#define EXPECT_THROWS(except, func)                                  \
    bool success(false);                                             \
                                                                     \
    try                                                              \
    {                                                                \
        func;                                                        \
    }                                                                \
    catch(const except& x)                                           \
    {                                                                \
        success = true;                                              \
    }                                                                \
                                                                     \
    if(!success) throw TestCase::TestFailed(__FILE__,                \
                                            __LINE__,                \
                                            #except " not thrown.")

#define EXPECT_NOTHROW(func)                 \
    try                                      \
    {                                        \
        func;                                \
    }                                        \
    catch(...)                               \
    {                                        \
        throw TestCase::TestFailed(	     \
            __FILE__,                        \
            __LINE__,                        \
            "Caught unexpected exception."); \
    }

#endif //TESTCASE_H
