#define CATCH_CONFIG_MAIN
#include "table.hpp"
#include "user.hpp"
#include "database.hpp"
#include <iostream>
#include "catch.hpp"
using namespace std;

// n1 rule, make the tests first!

TEST_CASE("Create database") 
{
    Database database;
    database.add_user(User{0, "Johan", 26});
    
    REQUIRE(database.get() == 1);
    REQUIRE(!(database.get() == 0));
}

TEST_CASE("Remove operations")
{
    Database database;
    User user{0, "Johan", 26};

    database.add_user(user);
    REQUIRE(database.get() == 1);
    
    database.remove_user(user);
    REQUIRE(database.get() == 0);
}

TEST_CASE("Invalid remove due to primary key")
{



}


TEST_CASE("Multiple tables tests")
{

}



