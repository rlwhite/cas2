#include "testCase.h"

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

