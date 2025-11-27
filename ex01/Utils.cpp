#include "Book.hpp"

void    PhonePrompt(void)
{
    PrintOut("----------------------------------", true);
    PrintOut("|     Welcome To Phone Menu      |", true);
    PrintOut("----------------------------------", true);
    PrintOut("----------------------------------", true);
    PrintOut("|      ADD | SEARCH | EXIT       |", true);
    PrintOut("----------------------------------", true);
    PrintOut("----------------------------------", true);
    PrintOut("|       Enter A COMMAND          |", true);
    PrintOut("----------------------------------", true);
}

void    AddContact(PhoneBook &pb)
{
    std::string input;
    Contact new_contact;

    PrintOut("Enter First Name: ", false);
    std::getline(std::cin, input);
    new_contact.SetFirstName(input);

    PrintOut("Enter Last Name: ", false);
    std::getline(std::cin, input);
    new_contact.SetLastName(input);

    PrintOut("Enter Nickname: ", false);
    std::getline(std::cin, input);
    new_contact.SetNickName(input);

    PrintOut("Enter Phone Number: ", false);
    std::getline(std::cin, input);
    new_contact.SetPhoneNumber(input);

    PrintOut("Enter Darkest Secret: ", false);
    std::getline(std::cin, input);
    new_contact.SetDarkestSecret(input);

    pb.AddContact(new_contact);
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int toInt(const std::string &s)
{
    std::stringstream ss(s);
    int x = 0;
    ss >> x;
    return x;
}


void DisplayContactDetails(Contact &c)
{
    PrintOut("First Name: " + c.GetFirstName(), true);
    PrintOut("Last Name: " + c.GetLastName(), true);
    PrintOut("Nickname: " + c.GetNickName(), true);
    PrintOut("Phone Number: " + c.GetPhoneNumber(), true);
    PrintOut("Darkest Secret: " + c.GetDarkestSecret(), true);
}

void SearchContact(PhoneBook &pb)
{
    int count = pb.GetCount();
    std::ostringstream stringbuffer;
    std::string idx;
    PrintOut("     Index|First Name| Last Name|  Nickname", true);

    for (int i = 0; i < count; i++)
    {
        std::string line = "";

        // index
        stringbuffer << i;
        idx = stringbuffer.str();
        line += std::string(10 - idx.length(), ' ') + idx + "|";

        // first name
        std::string fn = truncate(pb.GetContact(i).GetFirstName());
        line += std::string(10 - fn.length(), ' ') + fn + "|";

        // last name
        std::string ln = truncate(pb.GetContact(i).GetLastName());
        line += std::string(10 - ln.length(), ' ') + ln + "|";

        // nickname
        std::string nn = truncate(pb.GetContact(i).GetNickName());
        line += std::string(10 - nn.length(), ' ') + nn;

        PrintOut(line, true);
    }

    PrintOut("Enter index to view details: ", false);
    std::getline(std::cin, idx);
    int index = toInt(idx);
    if (index < 0 || index >= count)
    {
        PrintOut("Invalid index.", true);
        return ;
    }
    Contact c = pb.GetContact(index);
    // Display contact details function
    DisplayContactDetails(c);
}
