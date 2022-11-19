#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	public:
		Weapon();
		Weapon(const std::string string);
		~Weapon();

		std::string getType() const;
		void setType(const std::string type);
	private:
		std::string _type;
};

#endif
