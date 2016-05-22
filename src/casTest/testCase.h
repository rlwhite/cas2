#ifndef TESTCASE_H
#define TESTCASE_H

#include <string>

struct TestCase
{
    struct TestFailed
    {};

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

#endif //TESTCASE_H
