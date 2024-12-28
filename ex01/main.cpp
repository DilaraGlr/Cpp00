#include "phonebook.hpp"
#include <iomanip>
#include <cctype>
#include <iostream>

int main()
{
    Phonebook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            Contact contact;
            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string phone_number;
            std::string darkest_secret;

            std::cout << "Enter first name: ";
            std::getline(std::cin, first_name);
            contact.set_first_name(first_name);
            std::cout << "Enter last name: ";
            std::getline(std::cin, last_name);
            contact.set_last_name(last_name);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            contact.set_nickname(nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phone_number);
            contact.set_phone_number(phone_number);
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkest_secret);
            contact.set_darkest_secret(darkest_secret);
            phonebook.add_contact(contact);
        }
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
        {
            phonebook.exit_contact();
            break;
        }
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}

