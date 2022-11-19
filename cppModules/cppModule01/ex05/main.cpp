#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl herald;

    herald.complain("DEBUG");
    herald.complain("INFO");
    herald.complain("WARNING");
    herald.complain("ERROR");
    herald.complain("Wrong parameter");

    // std::string tmp;
    // while (1)
    // {
    //     std::cin >> tmp;
    //     herald.complain(tmp);
    // }

    return 0;
}

//TODO: leaks