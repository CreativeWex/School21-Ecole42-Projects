#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << RED "Wrong args number\nUsage: <program> <file name> <search> <replace>\n";
        return 1;
    }
    
    std::string buf;
    if (Sed::validateArgs(argv[2], argv[3]) || Sed::validateFile(argv[1]))
    {
        return 1;
    }
    Sed ob = Sed(argv[1], argv[2], argv[3]);
    ob.readFile();
    ob.replace();
    ob.writeToFile();

    return 0;
}