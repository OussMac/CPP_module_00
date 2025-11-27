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

void    PhoneBookLoop(PhoneBook &pb)
{
    (void)pb;
    std::string input;
    while (true)
    {
        PhonePrompt();
        PrintOut("Command: ", false);
        std::getline(std::cin, input);
        if (input.empty())
            break ;
        if (input == "ADD")
            AddContact(pb);
        else if (input == "SEARCH")
            SearchContact(pb);
        else if (input == "EXIT")
            break ;

        PrintOut("Your Command is: ", false);
        PrintOut(input, true);
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