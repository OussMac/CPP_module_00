#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private :
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    Contact();

    // Setters
    void    SetFirstName(std::string &fname);
    void    SetLastName(std::string &lname);
    void    SetNickName(std::string &nick);
    void    SetPhoneNumber(std::string &phone);
    void    SetDarkestSecret(std::string &secret);

    // Getters
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickName();
    std::string GetPhoneNumber();
    std::string GetDarkestSecret();
};

#endif