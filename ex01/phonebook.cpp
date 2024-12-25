/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diguler <diguler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:46:26 by diguler           #+#    #+#             */
/*   Updated: 2024/12/25 18:43:12 by diguler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : nextIndex(0), totalContacts(0) 
{
    std::cout << "PhoneBook initialized." << std::endl;
}

PhoneBook::~PhoneBook() 
{
    std::cout << "PhoneBook destroyed." << std::endl;
}

void PhoneBook::addContact(const Contact& contact) 
{
    contacts[nextIndex] = contact;  // Remplacement ou ajout
    nextIndex = (nextIndex + 1) % 8;  // Rotation circulaire
    if (totalContacts < 8)
        totalContacts++;  // On augmente le nombre total de contacts
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContacts() const 
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;  // Ligne séparatrice

    for (int i = 0; i < totalContacts; i++) 
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << (contacts[i].getFirstName().length() > 10
                                           ? contacts[i].getFirstName().substr(0, 9) + "."
                                           : contacts[i].getFirstName())
                  << "|"
                  << std::setw(10) << (contacts[i].getLastName().length() > 10
                                           ? contacts[i].getLastName().substr(0, 9) + "."
                                           : contacts[i].getLastName())
                  << "|"
                  << std::setw(10) << (contacts[i].getNickname().length() > 10
                                           ? contacts[i].getNickname().substr(0, 9) + "."
                                           : contacts[i].getNickname())
                  << std::endl;
    }
}

void PhoneBook::viewContact(int index) const 
{
    if (index < 0 || index >= totalContacts) 
    {
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

