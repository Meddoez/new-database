#define CATCH_CONFIG_MAIN
#include "table.hpp"
#include "user.hpp"
#include "database.hpp"
#include "loans.hpp"
#include <iostream>
#include "catch.hpp"
using namespace std;

// n1 rule, make the tests first!

TEST_CASE("Create database") 
{
    Database database;
    database.add_user(User{0, "Johan", 26});
    
    REQUIRE(database.get_users() == 1);
    REQUIRE(!(database.get_users() == 0));
}

TEST_CASE("Remove operations")
{
    Database database;
    User user{0, "Johan", 26};

    database.add_user(user);
    REQUIRE(database.get_users() == 1);
    
    database.remove_user(user);
    REQUIRE(database.get_users() == 0);
}

TEST_CASE("Create relationship")
{
    Database database;
    User user{0, "Johan", 26};
    Loan loan{0, 1, "2025-01-01"};

    database.add_user(user);
    database.add_loan(user, loan);
    
    REQUIRE(database.get_users() == 1);
    REQUIRE(database.get_loans() == 1);
}

// So im thinking that we have a user which owns the primary key, this we can not remove the user when it has a loan.
TEST_CASE("Invalid user remove due to primary key")
{
    Database database;
    User user{0, "Johan", 26};
    Loan loan{0, 1, "2025-01-01"};

    database.add_user(user);
    database.add_loan(user, loan);

    REQUIRE(database.get_users() == 1);
    REQUIRE(database.get_loans() == 1);

    REQUIRE_THROWS(database.remove_user(user)); 

}

TEST_CASE("Valid remove of user")
{
    Database database;
    User user{0, "Johan", 26};

    database.add_user(user);

    REQUIRE(database.get_users() == 1);

    database.remove_user(user);
    REQUIRE(database.get_users() == 0);

}


TEST_CASE("Multiple tables tests")
{

}



