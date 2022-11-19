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

void Harl::complain(std::string level)
{
    std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
	{
		if (!level_arr[i].compare(level))
		{
			(this->*(arr[i]))();
			return ;
		}
	}
	std::cout << RED "Error complain" RESET << std::endl;
}

void Harl::debug()
{
    std::cout << GRN "[ DEBUG ]\n" RESET 
        << "I love having extra bacon for"
        << "my 7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!\n\n";
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