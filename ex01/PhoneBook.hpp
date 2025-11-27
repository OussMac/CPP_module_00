#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
    Contact contacts[8];
    int     index;
    int     count;

    public:
    PhoneBook();

    // Getters
    int     GetCount();
    Contact GetContacts();

    // Management methods.
    void    AddContact(Contact &new_contact);
    Contact GetContact(int idx);
};

#endif