#pragma once
#include "database.hpp"
#include "table.hpp"
#include <string>

class JSON_Parser
{
public:

template <typename T>
void save_to_table(Table<T> const &table, std::string const &filename);

template <typename T>
void load_from_table(Table<T> &table, std::string const &filename);

void save_to_database(Database &database);
void load_from_database(Database &database);



private:


};

#include "json_parser.tpp"