#pragma once
#include <string>
#include <ostream>

struct User
{

    int id{0};
    std::string name;
    int age;

    int get_user_id() const
    {
        return id;
    }
    void to_json(std::ostream &file) const
    {
        file << "{" << std::endl;
        file << "  \"id\": " << id << "," << std::endl;
        file << "  \"name\": \"" << name << "\"," << std::endl;
        file << "  \"age\": " << age << std::endl;
        file << "}" << std::endl;
    }
};
