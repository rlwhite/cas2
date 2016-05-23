#include "testCase.h"

TestCase::TestFailed::TestFailed(const char* const file,
				   size_t line)
    : src_(file),
      line_(line)
{}

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

