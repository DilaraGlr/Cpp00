/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diguler <diguler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:03:13 by diguler           #+#    #+#             */
/*   Updated: 2024/12/25 19:13:59 by diguler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits> // Ajouté pour std::numeric_limits
#include "phonebook.hpp"

int main() 
{
    PhoneBook phoneBook;
    std::string command;

    while (true) 
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            // Ajouter un contact
        } else if (command == "SEARCH") {
            // Rechercher un contact
        } else if (command == "EXIT") {
            std::cout << "Exiting PhoneBook..." << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}

