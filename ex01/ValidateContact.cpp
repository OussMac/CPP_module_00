#include "Book.hpp"

bool ValidateCmd(std::string input, std::string cmd)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::islower(input[i]))
            input[i] = std::toupper(input[i]);
    }
    if (input == cmd)
        return (true);
    return (false);
}

bool    ValidateName(std::string &input, int name)
{
    if (name == 0)
    {
        for(size_t i = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (!std::isalpha(c))
                return (PrintOut(_RED" ❌ Error: Names should have only a-z A-Z", false), PrintOut(_RST, true), false);
        }
    }
    else if (name == 1)
    {
        for(size_t i = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (!std::isalpha(c) && !std::isdigit(c))
                return (PrintOut(_RED" ❌ Error: Nicknames should have only a-z A-Z 0-9", false), PrintOut(_RST, true), false);
        }
    }
    else if (name == 2)
    {
        for(size_t i = 0; i < input.length(); i++)
        {
            char c = input[i];
            if (!std::isalpha(c) && !std::isdigit(c))
                return (PrintOut(_RED" ❌ Secret should have only a-z A-Z 0-9", false), PrintOut(_RST, true), false);
        }
    }

    return (true);
}

bool    ValidateNumber(std::string &input)
{
    for(size_t i = 0; i < input.length(); i++)
    {
        char c = input[i];
        if (!std::isdigit(c))
            return (PrintOut(_RED" ❌ Number should have only 0-9", false), PrintOut(_RST, true), false);
    }
    return (true);
}