#define CATCH_CONFIG_MAIN
#include "table.hpp"
#include "user.hpp"
#include "database.hpp"
#include "loans.hpp"
#include "json_parser.hpp"
#include <iostream>
#include "catch.hpp"
using namespace std;

// n1 rule, make the tests first!

TEST_CASE("Create database") 
{
    Database database;
    User user{0, "Johan", 26};
    database.add_user(user);
    
    REQUIRE(database.get_all_users().size() == 1);
    REQUIRE(!(database.get_all_users().size() == 0));
}

TEST_CASE("Remove operations")
{
    Database database;
    User user{0, "Johan", 26};

    database.add_user(user);
    REQUIRE(database.get_all_users().size() == 1);
    
    database.remove_user(user.id);
    REQUIRE(database.get_all_users().size() == 0);
}

TEST_CASE("Create relationship")
{
    Database database;
    User user{0, "Johan", 26};
    Loan loan{0, 1, "2025-01-01"};

    database.add_user(user);
    database.add_loan(user, loan);
    
    REQUIRE(database.get_all_users().size() == 1);
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

    REQUIRE(database.get_all_users().size() == 1);
    REQUIRE(database.get_loans() == 1);

    REQUIRE_THROWS(database.remove_user(user.id)); 

}

TEST_CASE("Valid remove of user")
{
    Database database;
    User user{0, "Johan", 26};

    database.add_user(user);

    REQUIRE(database.get_all_users().size() == 1);

    database.remove_user(user.id);
    REQUIRE(database.get_all_users().size() == 0);
}


TEST_CASE("Hashmap lookup tests")
{
    Database db;
    User user{0, "Johan", 26};

    db.add_user(user);

    REQUIRE(db.get_specific_user(0).id == 0);
    REQUIRE(db.get_specific_user(0).name == "Johan");
    REQUIRE(db.get_specific_user(0).age == 26);

    User user2{0, "Mohammed", 23};
    db.add_user(user2); 
    
    REQUIRE(db.get_specific_user(1).id == 1);
    REQUIRE(db.get_specific_user(1).name == "Mohammed");
    REQUIRE(db.get_specific_user(1).age == 23);
}

TEST_CASE("JSON save tests")
{
    JSON_Parser parser;
    Database db;
    User user{0, "Johan", 26};

    db.add_user(user);
    parser.save_to_table(db.get_user_table(), "users.json");
}


