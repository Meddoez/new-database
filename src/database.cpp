#include "database.hpp"

Database::Database()
{}

void Database::add_user(User user)
{
    m_users.insert(user);
}

void Database::remove_user(User user)
{
    if (user_has_loans(user.id))
    {
        throw std::runtime_error("Cannot remove user with active loan");    
    }
    m_users.remove(user.id);
}

size_t Database::get_users() const
{
   return m_users.get_all_rows(); 
}

// how do we link the loan to the user? we need to add a foreign key to the loan 
void Database::add_loan(User &user, Loan &loan)
{
    loan.user_id = user.id;
    m_loans.insert(loan);
}

void Database::remove_loan(Loan loan)
{
    m_loans.remove(loan.id);
}

size_t Database::get_loans() const
{
    return m_loans.get_all_rows();
}

bool Database::user_has_loans(int const &user_id) const
{
    for (auto const &loan : m_loans.get_rows())
    {
        if (loan.user_id == user_id)
        {
            return true;
        }
    }
    return false;
}

