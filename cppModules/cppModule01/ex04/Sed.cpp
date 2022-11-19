#include "Sed.hpp"

Sed::Sed(std::string filename, std::string first_str, std::string second_str)
{
    _filename = filename;
    _first_str = first_str;
    _second_str = second_str;
}

Sed::~Sed()
{

}
/*===================[METHODS]===================*/

bool Sed::validateArgs(std::string str1, std::string str2)
{
    if (str1 ==  "" || str2 == "") // порверка на пустоту строк
    {
        std::cerr << RED "Line is empty!\n" RESET;
        return (true);
    }

    return false;
}

bool Sed::validateFile(std::string filename)
{
    std::ifstream input;

    input.open(filename);
    if (!input.is_open())
    {
        std::cerr << RED "Can't open file " << filename << "\n";
        input.close();
        return true;
    }
    if ((input.peek()) == EOF)
    {
        std::cerr << RED "File is empty!\n" RESET;
        input.close();
        return true;
    }
    input.close();
    return false;
}

void Sed::readFile()
{
    std::ifstream input;
    std::string tmp;

    try
    {
        input.open(_filename);
        while (!input.eof())
        {
            if (std::getline(input, tmp))
            {
                _buf.append(tmp);
                _buf.append("\n");
            }
            else
            {
                _buf.append("\n");
            }
        }
        _buf.erase(_buf.size() - 1);
        input.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Sed::replace()
{
    size_t i = 0;

    while(i < _buf.length())
    {
        i = _buf.find(_first_str, i); // первое вхождение
        if (i == std::string::npos) // если не нашли никакого вхождения то выходим
        {
            break;
        }
        _buf.erase(i, _first_str.length()); // чистка первой подстроки в буфере
        _buf.insert(i,_second_str); // заменяется на вторую строку
        i += _second_str.length();//сдвигается cчетчик строки
    }
}

void Sed::writeToFile()
{
    std::ofstream output;
    if (!(_filename.find(".", 0) == std::string::npos)) // если нашли точку то стираем
			_filename.erase(_filename.find(".", 0));
    _filename.append(".replace");
    output.open(_filename);
    output << _buf;
}

/*===================[GETTERS]===================*/
std::string Sed::getFilename()
{
    return _filename;
}

std::string Sed::getFirstStr()
{
    return _first_str;
}
std::string Sed::getSecondStr()
{
    return _second_str;
}

/*===================[SETTERS]===================*/
void Sed::setFilename(std::string valueFilename)
{
    _filename = valueFilename;
}

void Sed::setFirstStr(std::string valueFirstStr)
{
    _first_str = valueFirstStr;
}
void Sed::setSecondStr(std::string valueSecondStr)
{
    _second_str = valueSecondStr;
}


//TODO: проверить