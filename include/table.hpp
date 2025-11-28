#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>


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
/// the primary key should be the id of the row and auto-increment, 

template <typename T>
class Table 
{
public:

    Table() : m_rows{}, m_next_id{0}
    {}

    void insert(T &row)
    {
        row.id = m_next_id++;
        m_rows.push_back(row);
        m_row_map[row.id] = row;
    }

    void remove(int const &id)
    {
        auto it {std::find_if(m_rows.begin(), m_rows.end(), [id](T const &row)
        {
            return row.id == id;
        })};

        if (it == m_rows.end())
        {
            throw std::out_of_range("No row with matching id");
        }
        m_rows.erase(it);
    }

    size_t get_all_rows() const
    {
        return m_rows.size();
    }

    std::vector<T> get_rows() const
    {
        return m_rows;
    }

    T& get_specific_row(int const &id)
    {
        return m_row_map[id];
    }

    void set_next_id(int const &id)
    {
        m_next_id = id;
    }

    void insert_loaded(T const &row) 
    {
        m_rows.push_back(row);
    }

    void clear_rows() 
    {
        m_rows.clear();
    }

    int get_next_id() const
    {
        return m_next_id;
    }

private:
    std::vector<T> m_rows;
    int m_next_id;
    std::unordered_map<int, T> m_row_map;
};



