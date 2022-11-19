/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2022/07/07 by jnidorin                   #+#    #+#             */
/*   Updated: 2022/07/07 by jnidorin                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    this->_flagNotNull = false;
}

Contact::~Contact()
{

}

/*===================[METHODS]===================*/
void Contact::display(int index)
{
    std::cout << "=========[" << YEL << index << RESET << "]=========\n";
    std::cout << "Name: " << _name << "\n";
    std::cout << "Surname: " << _surname << "\n";
    std::cout << "Nickname: " << _nickname << "\n";
    std::cout << "Darkest Secret: " << _darkestSecret << "\n";
    std::cout << "Favorite meal: " << _favoriteMeal << "\n";
    std::cout << "Other information: " << _phoneNumber << "\n";
    std::cout << "=====================\n";
}

/*===================[GETTERS]===================*/
std::string Contact::getName()
{
    return _name;
}

std::string Contact::getSurname()
{
    return _surname;
}

std::string Contact::getNickname()
{
    return _nickname;
}

std::string Contact::getDarkestSecret()
{
    return _darkestSecret;
}

bool Contact::getFlagNotNull()
{
    return _flagNotNull;
}

std::string Contact::getFavoriteMeal()
{
    return _favoriteMeal;
}

std::string Contact::getPhoneNumber()
{
    return _phoneNumber;
}

/*===================[SETTERS]===================*/
void Contact::setName(std::string valueName)
{
    _name = valueName;
}

void Contact::setSurname(std::string valueSurname)
{
    _surname = valueSurname;
}

void Contact::setNickname(std::string valueNickname)
{
    _nickname = valueNickname;
}

void Contact::setDarkestSecret(std::string valueDarkestSecret)
{
    _darkestSecret = valueDarkestSecret;
}

void Contact::setFlagNotNuLL()
{
    _flagNotNull = true;
}

void Contact::setFavoriteMeal(std::string valueFavoriteMeal)
{
    _favoriteMeal = valueFavoriteMeal;
}

void Contact::setPhoneNumber(std::string valueOtherInfo)
{
    _phoneNumber = valueOtherInfo;
}
