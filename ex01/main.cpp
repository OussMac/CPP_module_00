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

static void ExitFunction(void)
{
    PrintOut(_RED"----------------------------------", true);
    PrintOut("|     📝 EXITING PHONEBOOK       |", true);
    PrintOut("----------------------------------", true);
}

void PhoneBookLoop(PhoneBook &pb)
{
    std::string input;

    while (true)
    {
        PrintOut(_CLEARSCRN, false);
        PhonePrompt();
        CommandPrompt();

        if (!std::getline(std::cin, input))
            return;

        if (ValidateCmd(input, "ADD"))
        {
            if (AddContact(pb) == EXIT_FAILURE)
                return ;
        }
        else if (ValidateCmd(input, "SEARCH"))
        {
            if (SearchContact(pb) == EXIT_FAILURE)
                return ;
        }
        else if (ValidateCmd(input, "EXIT"))
        {
            ExitFunction();
            return ;
        }
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