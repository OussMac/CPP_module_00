#include <iostream>

void print_noise(void)
{
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void print_loud(char **argv)
{
    for (int i = 0; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (isalpha(argv[i][j]) && islower(argv[i][j]))
                argv[i][j] -= 32; 
        }
    }
    for (int i = 0; argv[i]; i++)
        std::cout << argv[i];
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        print_noise();
    else
        print_loud(argv + 1);
    return (0);
}