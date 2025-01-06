#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"

class Phonebook
{
    private:
        Contact contacts[8];
        int contact_count;

    public:
        Phonebook();
        ~Phonebook();

        void add_contact(Contact contact);
        void search_contact() const;
        void exit_contact() const;
        void print_contact(Contact contact) const;
        std::string _trunc(std::string str) const;
};

#endif
