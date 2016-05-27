#include "testCase.h"

TestCase::TestFailed::TestFailed(const char* const file,
				 size_t line,
				 const char* const msg)
    : src_(file),
      line_(line),
      msg_(msg)
{}

TestCase::TestFailed::~TestFailed() throw()
{}

const char* TestCase::TestFailed::what() const
{
    return msg_;
}

TestCase::~TestCase()
{}

void TestCase::setUp()
{}

void TestCase::tearDown()
{}

const std::string& TestCase::name() const
{
    return name_;
}

void TestCase::setName(const std::string& name)
{
    name_ = name;
}

