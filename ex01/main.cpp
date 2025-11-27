#include "Book.hpp"

static void PrintOut(std::string str, bool newline)
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
        PrintOut("Welcome To PhoneBook!", true);
        std::getline(std::cin, input);

        PrintOut("Hello ", false);
        PrintOut(input, true);
    }
}


int main(int argc, char *argv[])
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "This program does not take arguments." << std::endl;
        return (1);
    }
    PhoneBook phonebook;
    PhoneBookLoop(phonebook);
    return (0);
}