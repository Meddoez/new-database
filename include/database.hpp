#pragma once

#include "table.hpp"
#include "user.hpp"
#include "loans.hpp"
#include <unordered_map>


class Database 
{
public:

    Database();

    void add_user(User user);
    void remove_user(User user);  
    size_t get_users() const;

    void add_loan(User &user, Loan &loan);
    void remove_loan(Loan loan);
    size_t get_loans() const;
    bool user_has_loans(int const &user_id) const;

private:
    Table<User> m_users;
    Table<Loan> m_loans;
};
