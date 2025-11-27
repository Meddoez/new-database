#include "json_parser.hpp"
#include <fstream>
#include <stdexcept>



template <typename T>
void JSON_Parser::save_to_table(Table<T> const &table, std::string const &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    for (auto const &row : table.get_rows())
    {
        row.to_json(file);
    }
    file.close();
}

template <typename T> 
void JSON_Parser::load_from_table(Table<T> &table, std::string const &filename)
{



}
