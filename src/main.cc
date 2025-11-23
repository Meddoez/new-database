#include "database.hpp"
#include <iostream>
#include <sstream>

enum class Choice
{
    CREATE_USER,
    SELECT_ALL,
    DELETE_USER,
    GET_USER
};

Choice command_parser(std::string const &first_word, std::string const &second_word)
{
    if (first_word == "CREATE" && second_word == "USER")
        {
            return Choice::CREATE_USER;
        }
    else
    {
        throw std::runtime_error("Invalid command, please try again");
    }
}

int main()
{
    std::cout << "Welcome to my custom database" << std::endl;
    std::cout << "Commands: 1. CREATE USER, 2. SELECT * FROM, 3. DELETE USER id=. " << std::endl;
    
    std::string first_word, second_word;

    Database db;
    while (std::cin >> first_word >> second_word) 
    { 
        try
        {
            Choice command = command_parser(first_word, second_word);
        switch(command)
        {
            case Choice::CREATE_USER:
            {
                User user;
                std::cin >> user.name >> user.age;
                db.add_user(user);
                std::cout << "User: " << user.name << " created with id: " << user.id << std::endl;
                break;
            }
            case Choice::SELECT_ALL:
            {

            }
            case Choice::DELETE_USER:
            {

            }

            case Choice::GET_USER:
            {

            }
            }
        }
        catch (std::runtime_error &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }



}
