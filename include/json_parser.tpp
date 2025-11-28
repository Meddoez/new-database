#include "json_parser.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>

using nlohmann::json;

template <typename T>
void JSON_Parser::save_to_table(const Table<T>& table, const std::string& filename)
{
    json j;

    // Save next_id
    j["next_id"] = table.get_next_id();

    // Save all rows
    j["rows"] = json::array();
    for (const auto& row : table.get_rows())
    {
        j["rows"].push_back(row.to_json());  // T must implement to_json()
    }

    std::ofstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file: " + filename);

    file << j.dump(4);  // pretty print
}

template <typename T>
void JSON_Parser::load_from_table(Table<T>& table, const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // If file doesn't exist yet → treat as empty table
        return;
    }

    json j;
    file >> j;

    // Load next_id
    table.set_next_id(j.value("next_id", 0));

    // Clear existing rows
    table.clear_rows();

    // Load rows
    for (const auto& obj : j["rows"])
    {
        T row = T::from_json(obj);  // T must implement from_json(json)
        table.insert_loaded(row);   // Insert without assigning new ID
    }
}