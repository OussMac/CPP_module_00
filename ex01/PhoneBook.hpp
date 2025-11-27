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

    public:
    PhoneBook();
};

#endif