#pragma once
#include <vector>
#include <string>
#include <unoredered_map>

// the idea is to create a relational database, 
// + good for finding specific data fast, 
// we want to create a one-to-many relationship between table 1:N
// + columns
// + rows
// + constraints
// + indices
// + foreign keys
// + primary keys
// + unique keys
// + checks
// + triggers
// parent table is the one that contains the foreign key 
// child table is the one that contains the primary key
// the relationship is defined by the foreign key in the child table
// the foreign key is a column that references the primary key of the parent table
// the primary key is a column that uniquely identifies each row in the parent table
// the unique key is a column that uniquely identifies each row in the child table
// the check is a condition that must be true for each row in the table
// the trigger is a function that is executed when a row is inserted, updated, or deleted
// the index is a data structure that speeds up the retrieval of data
// the foreign key is a column that references the primary key of the parent table

// https://vertabelo.com/blog/one-to-many-relationship/

////////////////// THE IDEA /////////////////////
/// We want to create a table for users that are able to loan books, the parent table is then the user, the child tables are loan, what book, authors etc.
/// They can then have multiple child tables, ie giving the name one-to-many-relationship. 
/// the child table should always have a reference to one index in the parent table, ie they should be named the same for relevance.

template <typename T>
class Table 
{
public:

    Table();

    void insert(T const &row);
    void remove(int const &id);


    

private:
    std::vector<T> m_rows;

};
