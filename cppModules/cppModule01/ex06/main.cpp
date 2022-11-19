#include "Harl.hpp"

int translate(std::string input)
{
    std::string alphabet[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (size_t i = 0; i < 4; i++)
    {
        if (input == alphabet[i])
        {
            return i;
        }
    }
    return 5;
}

int main(int argc, char **argv)
{
    Harl herald;

    if (argc != 2)
    {
        std::cerr << RED "Wrong parameters number\n"
        << "Usage: ./harlFilter <arg>\n";
        return 1;
    }
    herald.filter(translate(argv[1]));

    return 0;
}

//TODO: leaks