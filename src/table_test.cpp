#define CATCH_CONFIG_MAIN
#include "table.hpp"
#include "user.hpp"
#include "database.hpp"
#include <iostream>
#include "catch.hpp"
using namespace std;

// n1 rule, make the tests first!

TEST_CASE("Table basic operations", "[table]") {
    // Column col1{"Name", DataType::STRING};
    // Column col2{"Age", DataType::INT};
    // std::vector<Column> columns = {col1, col2};

    // TableData data{columns, {}};
    // Table table(data);
    //
    Database database;
    database.add_user(User{0, "Johan", 26});
    

    REQUIRE(database.get() == 1);
    REQUIRE(!(database.get() == 0));


}
