#include "contact.hpp"

Contact Contact::contacts[8];

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}
Contact::~Contact()
{
    return;
}
int Contact::set_first_name(std::string first_name)
{
    int valid = 1;

    if(first_name.empty())
    {
        std::cout << "Invalid first name." << std::endl;
        valid = 0;
        return (0);
    }
    for(size_t i = 0; i < first_name.length(); i++)
    {
        if (!std::isalpha(first_name[i]))
        {
            std::cout << "Invalid first name." << std::endl;
            valid = 0;
            return (0);
        }
    }
    if (valid)
        this->first_name = first_name;
    return (1);
}
int Contact::set_last_name(std::string last_name)
{
    int valid = 1;

    if(last_name.empty())
    {
        std::cout << "Invalid last name." << std::endl;
        valid = 0;
        return (0);
    }
    for(size_t i = 0; i < last_name.length(); i++)
    {
        if (!std::isalpha(last_name[i]))
        {
            std::cout << "Invalid first name." << std::endl;
            valid = 0;
            return (0);
        }
    }
    if (valid)
        this->last_name = last_name;
    return (1);
}
int Contact::set_phone_number(std::string phone_number)
{
    int valid = 1;

    if(phone_number.empty())
    {
        std::cout << "Invalid phone number." << std::endl;
        valid = 0;
        return (0);
    }
    for(size_t i = 0; i < phone_number.length(); i++)
    {
        if (!std::isdigit(phone_number[i]))
        {
            std::cout << "Invalid phone number." << std::endl;
            valid = 0;
            return (0);
        }
    }
    if (valid)
        this->phone_number = phone_number;
    return (1);
}
int Contact::set_nickname(std::string nickname)
{
    if(nickname.empty())
    {
        std::cout << "Invalid nickname." << std::endl;
        return (0);
    }
    this->nickname = nickname;
    return (1);
}
int Contact::set_darkest_secret(std::string darkest_secret)
{
    if(darkest_secret.empty())
    {
        std::cout << "Invalid darkest secret." << std::endl;
        return (0);
    }
    this->darkest_secret = darkest_secret;
    return (1);
}


