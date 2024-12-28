#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{   
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        static Contact contacts[8];

    public:
        Contact();
        ~Contact();
        
        void set_first_name(std::string first_name) { this->first_name = first_name; };
        void set_last_name(std::string last_name) { this->last_name = last_name; };
        void set_nickname(std::string nickname) { this->nickname = nickname; };
        void set_phone_number(std::string phone_number) { this->phone_number = phone_number; };
        void set_darkest_secret(std::string _arkest_secret) { this->darkest_secret = _arkest_secret; };
        
        std::string get_first_name() const { return this->first_name; };
        std::string get_last_name() const { return this->last_name; };
        std::string get_nickname() const { return this->nickname; };
        std::string get_phone_number() const { return this->phone_number; };
        std::string get_darkest_secret() const { return this->darkest_secret; };

};

#endif
