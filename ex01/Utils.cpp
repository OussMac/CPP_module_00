#include "Book.hpp"

void PhonePrompt(void)
{
    PrintOut(_BLU, false);
    PrintOut("----------------------------------", true);

    PrintOut("|  📞  ", false);
    PrintOut(_GRN, false);
    PrintOut("Welcome To Phone Menu", false);
    PrintOut(_BLU, false);
    PrintOut("     |", true);

    PrintOut("----------------------------------", true);
    PrintOut("----------------------------------", true);

    PrintOut("|  📝   ", false);
    PrintOut(_BLU, false);
    PrintOut("ADD", false);
    PrintOut(_BLU, false);
    PrintOut(" | ", false);
    PrintOut(_ORG, false);
    PrintOut("SEARCH", false);
    PrintOut(_BLU, false);
    PrintOut(" | ", false);
    PrintOut(_RED, false);
    PrintOut("EXIT", false);
    PrintOut(_BLU, false);
    PrintOut("      |", true);

    PrintOut("----------------------------------", true);
    PrintOut("----------------------------------", true);

    PrintOut("|  💬    ", false);
    PrintOut(_GRN, false);
    PrintOut("Enter A COMMAND", false);
    PrintOut(_BLU, false);
    PrintOut("         |", true);

    PrintOut("----------------------------------", false);
    PrintOut(_RST, true);
}


bool    safe_getline(std::string &input_ref)
{
    if (!std::getline(std::cin, input_ref))
    {
        std::cout << std::endl;
        return (false);
    }
    return (true);
}

void AddContact(PhoneBook &pb)
{
    std::string input;
    Contact new_contact;

    PrintOut("Enter First Name: ", false);
    if (!safe_getline(input) || input.empty()) 
        return;
    if (ValidateName(input, 0))
        new_contact.SetFirstName(input);
    else
        return ;

    PrintOut("Enter Last Name: ", false);
    if (!safe_getline(input) || input.empty()) 
        return ;
    if (ValidateName(input, 0))
        new_contact.SetLastName(input);
    else
        return ;

    PrintOut("Enter Nickname: ", false);
    if (!safe_getline(input) || input.empty())
        return;
    if (ValidateName(input, 1))
        new_contact.SetNickName(input);
    else
        return ;

    PrintOut("Enter Phone Number: ", false);
    if (!safe_getline(input) || input.empty())
        return;
    if (ValidateNumber(input))
        new_contact.SetPhoneNumber(input);
    else
        return ;

    PrintOut("Enter Darkest Secret: ", false);
    if (!safe_getline(input) || input.empty())
        return;
    if (ValidateName(input, 2))
        new_contact.SetDarkestSecret(input);
    else
        return ;

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
    std::string idx;
    PrintOut("     Index|First Name| Last Name|  Nickname", true);

    for (int i = 0; i < count; i++)
    {
        std::string line = "";

        // index
        std::ostringstream stringbuffer;
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
    if (!safe_getline(idx) || idx.empty())
        return ;
    int index = toInt(idx);
    if (index < 0 || index >= count || !ValidateNumber(idx))
    {
        PrintOut("Invalid index.", true);
        return ;
    }
    Contact c = pb.GetContact(index);
    // Display contact details function
    DisplayContactDetails(c);
}
