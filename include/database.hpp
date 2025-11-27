#pragma once

#include "table.hpp"
#include "user.hpp"
#include "loans.hpp"
#include <unordered_map>

// perhaps add some sort of authentication layer? 
// maybe add a layer of encryption to the database?
// different authorities for different users? admin, user, guest?


class Database 
{
public:

    Database();

    void add_user(User &user);
    void remove_user(int const &id);  
    std::vector<User> get_all_users() const;

    void add_loan(User &user, Loan &loan);
    void remove_loan(Loan loan);
    size_t get_loans() const;
    bool user_has_loans(int const &user_id) const;

    User get_specific_user(int const &user_id);
    Table<User>& get_user_table();
    Table<Loan>& get_loan_table();

private:
    Table<User> m_users;
    Table<Loan> m_loans;

};
