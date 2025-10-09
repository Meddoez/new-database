#pragma once

#include "table.hpp"
#include "user.hpp"


class Database 
{
public:

    Database();

    void add_user(User const &user);
    
    size_t get() const;

private:
    Table<User> m_users;


};