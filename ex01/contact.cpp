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

