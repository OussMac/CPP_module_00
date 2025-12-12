#include "Book.hpp"

void    PrintOut(std::string str, bool newline)
{
    if (newline){
        std::cout << str << std::endl;
    }
    else {
        std::cout << str;
    }
}

static  void CommandPrompt(void)
{
    PrintOut(_GRN, false);
    PrintOut("Command: ", false);
    PrintOut(_RST, false);

}

void PhoneBookLoop(PhoneBook &pb)
{
    std::string input;

    while (true)
    {
        PhonePrompt();
        CommandPrompt();

        if (!std::getline(std::cin, input))
            return;

        if (ValidateCmd(input, "add"))
            AddContact(pb);
        else if (ValidateCmd(input, "search"))
            SearchContact(pb);
        else if (ValidateCmd(input, "exit"))
            return ;
    }
}

int main(int argc, char *argv[])
{
    (void)argv;
    if (argc != 1)
    {
        PrintOut("This program does not take arguments.", true);
        return (1);
    }
    PhoneBook phonebook;
    PhoneBookLoop(phonebook);
    return (0);
}