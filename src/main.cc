#include "database.hpp"
#include "json_parser.hpp"
#include <iostream>
#include <sstream>

enum class Choice
{
    CREATE_USER,
    SELECT_ALL,
    DELETE_USER,
    GET_USER,
    EXIT
};

Choice command_parser(std::string const &first_word, std::string const &second_word)
{
    if (first_word == "CREATE" && second_word == "USER")
        {
            return Choice::CREATE_USER;
        }
    else if (first_word == "SELECT" && second_word == "ALL")
        {
            return Choice::SELECT_ALL;
        }
    else if (first_word == "DELETE" && second_word == "USER")
        {
            return Choice::DELETE_USER;
        }
    else
    {
        throw std::runtime_error("Invalid command, please try again");
    }
}

int main()
{
    std::cout << "Welcome to my custom database" << std::endl;
    std::cout << "Commands: 1. CREATE USER, 2. SELECT ALL, 3. DELETE USER id=. " << std::endl;
    
    std::string first_word, second_word;

    Database db;
    JSON_Parser parser;
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
                parser.save_to_table(db.get_user_table(), "users.json");
                std::cout << "User: " << user.name << " created with id: " << user.id << std::endl;
                break;
            }
            case Choice::SELECT_ALL:
            {
                for (auto const &user : db.get_all_users())
                {
                    std::cout << "User: " << user.name << " age:" << user.age << " with id: " << user.id << std::endl;
                }
                break;
            }
            case Choice::DELETE_USER:
            {
                int id;
                std::cin >> id;
                db.remove_user(id);
                std::cout << "User with id: " << id << " deleted" << std::endl;
                break;
            }
            case Choice::GET_USER:
            {

            }
            case Choice::EXIT:
            {
                std::cout << "Exiting program" << std::endl;
                break;
            }
        }
        catch (std::runtime_error &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    }


}
