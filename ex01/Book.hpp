#ifndef BOOK_HPP
# define BOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

#define _CLEARSCRN "\033[2J\033[1;1H"

// Regular Colors
#define _RED   "\033[0;31m"
#define _GRN   "\033[0;32m"
#define _YLW   "\033[0;33m"
#define _BLU   "\033[0;34m"
#define _MAG   "\033[0;35m"
#define _CYN   "\033[0;36m"
#define _WHT   "\033[0;37m"
#define _ORG   "\033[0;38;5;208m"
#define _BORG  "\033[1;38;5;208m"
#define _RST   "\033[0m"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void    PhonePrompt(void);
void    PrintOut(std::string str, bool newline);
int     AddContact(PhoneBook &pb);
int     SearchContact(PhoneBook &pb);
bool    safe_getline(std::string &input_ref);
bool    ValidateCmd(std::string input, std::string cmd);
bool    ValidateName(std::string &input, int name);
bool    ValidateNumber(std::string &input);
int     ValidationErrorHold(void);


#endif