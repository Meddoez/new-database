#pragma once
#include <string>
#include <ostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct User
{

    int id{0};
    std::string name;
    int age;

    std::string get_name() const
    {
        return name;
    }
    int get_age() const
    {
        return age;
    }
    int get_user_id() const
    {
        return id;
    }

    json to_json() const {
    return json{
        {"id", id},
        {"name", name},
        {"age", age}
    };
    }

    static User from_json(const json& j) {
        User u;
        u.id   = j.at("id").get<int>();
        u.name = j.at("name").get<std::string>();
        u.age  = j.at("age").get<int>();
        return u;
    }
};
