#include "phonebook.hpp"

Phonebook::Phonebook()
{
    this->contact_count = 0;
}
void Phonebook::add_contact(Contact contact)
{
    static int oldest_index = 0; // Garde une trace du plus ancien contact

    if (this->contact_count < 8)
    {
        this->contacts[this->contact_count] = contact;
        this->contact_count++;
    }
    else
    {
        std::cout << "Phonebook is full. Replacing the oldest contact." << std::endl;
        this->contacts[oldest_index] = contact; // Remplace le contact le plus ancien
        oldest_index = (oldest_index + 1) % 8;  // Passe au prochain index circulairement
    }
}

void Phonebook::search_contact() const
{
    std::string index;
    int i;

    if (this->contact_count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "     index|first name| last name|  nickname| phone num|  secret" << std::endl;
    for (i = 0; i < this->contact_count; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << this->contacts[i].get_first_name().substr(0, 10) << "|";
        std::cout << std::setw(10) << this->contacts[i].get_last_name().substr(0, 10) << "|";
        std::cout << std::setw(10) << this->contacts[i].get_nickname().substr(0, 10) << "|";
        std::cout << std::setw(10) << this->contacts[i].get_phone_number().substr(0, 10) << "|";
        std::cout << std::setw(10) << this->contacts[i].get_darkest_secret().substr(0, 10) << std::endl;
    }

    std::cout << "Enter index: ";
    std::getline(std::cin, index);
    if (index.length() == 1 && isdigit(index[0]))
    {
        i = index[0] - '0';
        if (i > 0 && i <= this->contact_count)
            this->print_contact(this->contacts[i - 1]);
        else
            std::cout << "Invalid index." << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}

void Phonebook::print_contact(Contact contact) const
{
    std::cout << "First name: " << contact.get_first_name() << std::endl;
    std::cout << "Last name: " << contact.get_last_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
}

void Phonebook::exit_contact() const
{
    std::cout << "Exiting phonebook." << std::endl;
}

Phonebook::~Phonebook()
{
    return;
}
