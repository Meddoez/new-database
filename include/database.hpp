#pragma once

#include "table.hpp"
#include "user.hpp"


class Database 
{
public:

    Database();

    void add_user(User user);
    void remove_user(User user);  
    size_t get() const;

private:
    Table<User> m_users;

};
