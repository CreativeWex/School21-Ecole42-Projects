#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

# define RED	"\x1b[31m"
# define BLU	"\x1B[34m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define RESET  "\x1B[0m"

class Sed
{
    public:
        Sed(std::string filename, std::string first_str, std::string second_str);
        ~Sed();
    /*===================[METHODS]===================*/
    static bool validateArgs(std::string str1, std::string str2);
    static bool validateFile(std::string filename);
    void readFile();
    void replace();
    void writeToFile();

    /*===================[GETTERS]===================*/
        std::string getFilename();
        std::string getFirstStr();
        std::string getSecondStr();

    /*===================[SETTERS]===================*/
        void setFilename(std::string valueFilename);
        void setFirstStr(std::string valueFirstStr);
        void setSecondStr(std::string valueSecondStr);

    private:
        std::string _filename;
        std::string _first_str;
        std::string _second_str;
        std::string _buf;
};

#endif