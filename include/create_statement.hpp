#pragma once
#include "statement.hpp"
#include <string> 

// CREATE TABLE **** (...);
class Create_statement : public Statement
{
public:
    Create_statement(std::string const& table_name);

private:
    std::string m_table_name;
};

