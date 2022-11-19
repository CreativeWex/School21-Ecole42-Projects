# define YEL	"\x1B[33m"
# define RESET  "\x1B[0m"

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

    std::cout << YEL "Adresses:\n" RESET;
	std::cout << "string:\t\t" << &string << "\n";
    std::cout << "stringPTR:\t" << stringPTR << "\n";
    std::cout << "stringREF:\t" << &stringREF << "\n";
    std::cout << "==========================================\n";

    std::cout << YEL "Values:\n" RESET;
	std::cout << "string:\t\t" << string << "\n";
    std::cout << "stringPTR:\t" << *stringPTR << "\n";
    std::cout << "stringREF:\t" << stringREF << "\n";
    std::cout << "==========================================\n";

	return 0;
}