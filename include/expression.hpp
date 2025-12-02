#pragma once
#include <string>


// base class for all SQL expressions
class Expression
{
public:

    virtual ~Expression() = default;

    virtual std::string to_sql() const = 0;



private:

};