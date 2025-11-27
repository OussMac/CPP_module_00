#include "Contact.hpp"

Contact::Contact()
{
    std::cout << "Contact Created!" << std::endl;
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

void Contact::SetFirstName(std::string &fname)
{
    first_name = fname;
}

void Contact::SetLastName(std::string &lname)
{
    last_name = lname;
}

void Contact::SetNickName(std::string &nick)
{
    nickname = nick;
}

void Contact::SetPhoneNumber(std::string &phone)
{
    phone_number = phone;
}

void Contact::SetDarkestSecret(std::string &secret)
{
    darkest_secret = secret;
}

std::string Contact::GetFirstName()
{
    return first_name;
}

std::string Contact::GetLastName()
{
    return last_name;
}

std::string Contact::GetNickName()
{
    return nickname;
}

std::string Contact::GetPhoneNumber()
{
    return phone_number;
}

std::string Contact::GetDarkestSecret()
{
    return darkest_secret;
}
