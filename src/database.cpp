#include "database.hpp"

Database::Database()
{}



void Database::add_user(User user)
{
    
    m_users.insert(user);
}

void Database::remove_user(User user)
{
    m_users.remove(user.id);
}

size_t Database::get() const
{
   return m_users.get_all_rows(); 
}
