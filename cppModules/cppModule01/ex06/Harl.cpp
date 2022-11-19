#include "Harl.hpp"

Harl::Harl()
{
    arr[0] = &Harl::debug;
	arr[1] = &Harl::info;
	arr[2] = &Harl::warning;
	arr[3] = &Harl::error;
}

Harl::~Harl()
{

}

void Harl::filter(int index)
{
    switch (index)
    {
        case 0:
            complain(0);
            break;
        case 1:
            complain(1);
            break;
        case 2:
            complain(2);
            break;
        case 3:
            complain(3);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}

void Harl::complain(int index)
{
    std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (size_t i = index; i < 4; i++)
    {
        (this->*(arr[i]))();
    } 
}

void Harl::debug()
{
    std::cout << GRN "[ DEBUG ]\n" RESET 
        << "I love having extra bacon for"
        << "my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
}

void Harl::info()
{
    std::cout << CYN "[ INFO ]\n" RESET 
            << "I cannot believe adding extra bacon costs more money.\n"
            << "You didn’t put enough bacon in my burger!\n"
            << "If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning()
{
    std::cout << YEL "[ WARNING ]\n" RESET
        << "I think I deserve to have some extra bacon for free.\n"
        << "I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error()
{
    std::cout << RED "[ ERROR ]\n" RESET
    << "This is unacceptable! I want to speak to the manager now.\n\n";
}