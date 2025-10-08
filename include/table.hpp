#pragma once

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



class Table 
{
public:

    Table();
  

    

private:
    

};