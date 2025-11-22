#pragma once
#include <string>

struct User
{

    int id{0};
    std::string name;
    int age;

    int get_user_id() const
    {
        return id;
    }
};
