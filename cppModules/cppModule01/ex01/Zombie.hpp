#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        
        void announce() const;
        void setName(std::string nameValue);

    private:
        std::string _name;

};  

#endif