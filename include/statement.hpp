#pragma once

enum class Statement_type
{
   CREATE_TABLE,
   INSERT,
   DELETE,
   SELECT 
};

// base class for all SQL statements
class Statement
{
public:
    Statement(Statement_type type) : m_type(type) {} 

    virtual ~Statement() = default;

private:
   Statement_type m_type; 
};