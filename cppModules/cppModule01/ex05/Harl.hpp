#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

# define RED	"\x1b[31m"
# define CYN	"\x1B[36m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define RESET  "\x1B[0m"

class Harl
{
    public:
        Harl();
        ~Harl();

        void complain(std::string level);

    private:
        void (Harl::*arr[4])(void);

        void debug();
        void info();
        void warning();
        void error();
};

#endif