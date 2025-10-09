#include "database.hpp"

Database::Database()
{}



void Database::add_user(User const &user)
{
    m_users.insert(user);
}

size_t Database::get() const
{
   return m_users.get_all_rows(); 
}