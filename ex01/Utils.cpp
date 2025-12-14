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

int ValidationErrorHold(void)
{
    PrintOut(_RED" ❌ All fields Must be filled", true);
    PrintOut(_GRN"Press ENTER to return to Menu...", false);
    PrintOut(_RST, false);
    std::string enter;
    if (!safe_getline(enter))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}


int AddContact(PhoneBook &pb)
{
    std::string input;
    Contact new_contact;

    PrintOut(_BLU"----------------------------------", true);
    PrintOut("|       📝 ADD A Contact         |", true);
    PrintOut("----------------------------------", true);

    PrintOut("Enter First Name: ", false);
    PrintOut(_RST, false);
    if (!safe_getline(input)) 
        return (EXIT_FAILURE);
    if (!input.empty() && ValidateName(input, 0))
        new_contact.SetFirstName(input);
    else
        return (ValidationErrorHold());
    PrintOut(_BLU"Enter Last Name: ", false);
    PrintOut(_RST, false);
    if (!safe_getline(input)) 
        return (EXIT_FAILURE);
    if (!input.empty() && ValidateName(input, 0))
        new_contact.SetLastName(input);
    else
        return (ValidationErrorHold());

    PrintOut(_BLU"Enter Nickname: ", false);
    PrintOut(_RST, false);
    if (!safe_getline(input))
        return (EXIT_FAILURE);
    if (!input.empty() && ValidateName(input, 1))
        new_contact.SetNickName(input);
    else
        return (ValidationErrorHold());

    PrintOut(_BLU"Enter Phone Number: ", false);
    PrintOut(_RST, false);
    if (!safe_getline(input))
        return (EXIT_FAILURE);
    if (!input.empty() && ValidateNumber(input))
        new_contact.SetPhoneNumber(input);
    else
        return (ValidationErrorHold());

    PrintOut(_BLU"Enter Darkest Secret: ", false);
    PrintOut(_RST, false);
    if (!safe_getline(input))
        return (EXIT_FAILURE);
    if (!input.empty() && ValidateName(input, 2))
        new_contact.SetDarkestSecret(input);
    else
        return (ValidationErrorHold());

    pb.AddContact(new_contact);
    return (EXIT_SUCCESS);
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
    if (c.GetFirstName().empty())
    {
        PrintOut(_RED" ❌ Contact is empty.", true);
        PrintOut(_RST, false);
        return ;
    }
    PrintOut(_YLW"----- Contact Details -----", true);
    PrintOut("First Name: " + c.GetFirstName(), true);
    PrintOut("Last Name: " + c.GetLastName(), true);
    PrintOut("Nickname: " + c.GetNickName(), true);
    PrintOut("Phone Number: " + c.GetPhoneNumber(), true);
    PrintOut("Darkest Secret: " + c.GetDarkestSecret(), true);
    PrintOut(_RST, false);
}

int SearchContact(PhoneBook &pb)
{
    int count = pb.GetCount();
    std::string idx;

    PrintOut(_ORG"----------------------------------", true);
    PrintOut("|   📝 Search For Contacts       |", true);
    PrintOut("----------------------------------", true);

    PrintOut("     Index|First Name| Last Name|  Nickname", true);

    for (int i = 0; i < count; i++)
    {
        std::string line = "";

        std::ostringstream stringbuffer;
        stringbuffer << i;
        idx = stringbuffer.str();
        line += std::string(10 - idx.length(), ' ') + idx + "|";

        std::string fn = truncate(pb.GetContact(i).GetFirstName());
        line += std::string(10 - fn.length(), ' ') + fn + "|";

        std::string ln = truncate(pb.GetContact(i).GetLastName());
        line += std::string(10 - ln.length(), ' ') + ln + "|";

        std::string nn = truncate(pb.GetContact(i).GetNickName());
        line += std::string(10 - nn.length(), ' ') + nn;

        PrintOut(line, true);
    }
    PrintOut(_RST, false);
    PrintOut(_GRN"Enter index to view details: ", false);
    PrintOut(_RST, false);
    if (!safe_getline(idx))
        return (EXIT_FAILURE);
    int index = toInt(idx);
    if (idx.empty() || (index < 0 || index >= count || !ValidateNumber(idx)))
    {
        PrintOut(_RED" ❌ Invalid index range.", true);
        PrintOut(_RST, false);
        return (ValidationErrorHold());
    }
    Contact c = pb.GetContact(index);

    DisplayContactDetails(c);

    PrintOut(_GRN"Press ENTER to return to Menu...", false);
    PrintOut(_RST, false);
    std::string enter;
    if (!safe_getline(enter))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
