/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diguler <diguler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:44:26 by diguler           #+#    #+#             */
/*   Updated: 2024/12/22 18:14:34 by diguler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

// Constructeur
Contact::Contact(const std::string& first, const std::string& last,
                 const std::string& nick, const std::string& phone,
                 const std::string& secret) 
    : firstName(first), lastName(last), nickname(nick), phoneNumber(phone), darkestSecret(secret) {}

// Méthode pour valider si un contact est valide
bool Contact::isValid() const 
{
    return !firstName.empty() && !lastName.empty() && !nickname.empty() && !phoneNumber.empty();
}

Contact::~Contact() {
    // Message pour montrer que le destructeur est appelé
    std::cout << "Destructing contact: " << firstName << " " << lastName << std::endl;
}
