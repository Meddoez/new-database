#pragma once
#include <string>

class sql_expression
{
public:
    sql_expression() = default;

    virtual ~sql_expression() = default;

    virtual std::string to_sql() const = 0;

private:

};