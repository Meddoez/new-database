#pragma once
#include "expression.hpp"




class Binary_expression : public Expression
{
public:
    Binary_expression() = default;


private:
    Expression* left;
    Expression* right;

};

