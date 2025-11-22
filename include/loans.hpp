#pragma once
#include <string>

// how do we link the loan to the user? we need to add a foreign key to the loan 
// table that references the user table, 
struct Loan
{
    int id = 0; // loans primary key
    int user_id = 0; // foregin key 
    
    std::string loan_date;
};