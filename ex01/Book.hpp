#ifndef BOOK_HPP
# define BOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

void    PhonePrompt(void);
void    PrintOut(std::string str, bool newline);
void    AddContact(PhoneBook &pb);
void    SearchContact(PhoneBook &pb);


#endif