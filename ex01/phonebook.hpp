/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diguler <diguler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:15:12 by diguler           #+#    #+#             */
/*   Updated: 2024/12/23 14:49:57 by diguler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook 
{
private:
    Contact contacts[8];  // Tableau statique pour stocker jusqu'à 8 contacts
    int nextIndex;        // Index du prochain contact à remplacer (si on dépasse 8)
    int totalContacts;    // Nombre total de contacts ajoutés (max : 8)

public:
    PhoneBook();           // Constructeur par défaut
    ~PhoneBook();          // Destructeur

    void addContact(const Contact& contact);  // Ajouter un contact
    void displayContacts() const;             // Afficher la liste des contacts
    void viewContact(int index) const;        // Afficher un contact en détail
};

#endif


