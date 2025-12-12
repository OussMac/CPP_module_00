#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    // std::cout << "PhoneBook Created!" << std::endl;
    index = 0;
    count = 8;
}

void PhoneBook::AddContact(Contact &new_contact)
{
    contacts[index] = new_contact;
    index++;
    if (index >= 8)
        index = 0;
}

Contact PhoneBook::GetContact(int idx)
{
    return contacts[idx];
}

int PhoneBook::GetCount()
{
    return count;
}