/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diguler <diguler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:15:23 by diguler           #+#    #+#             */
/*   Updated: 2024/12/25 19:07:16 by diguler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
        // Constructeur
    Contact(const std::string& first = "", const std::string& last = "",
            const std::string& nick = "", const std::string& phone = "",
            const std::string& secret = "");

    ~Contact();
    
    // Getters en ligne
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }

    // Setters en ligne
    void setFirstName(const std::string& value) { firstName = value; }
    void setLastName(const std::string& value) { lastName = value; }
    void setNickname(const std::string& value) { nickname = value; }
    void setPhoneNumber(const std::string& value) { phoneNumber = value; }
    void setDarkestSecret(const std::string& value) { darkestSecret = value; }

    // Méthode pour valider si un contact est valide
    bool isValid() const;

};

#endif

