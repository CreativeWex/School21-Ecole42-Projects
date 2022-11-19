/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2022/07/07 by jnidorin                   #+#    #+#             */
/*   Updated: 2022/07/07 by jnidorin                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Header.hpp"

class Contact
{
    private:
        std::string _name;
        std::string _surname;
        std::string _nickname;
        std::string _darkestSecret;
        std::string _favoriteMeal;
        std::string _phoneNumber;
        bool _flagNotNull;

    public:
        Contact();
        ~Contact();
        /*===================[METHODS]===================*/
        void display(int index);

        /*===================[GETTERS]===================*/
        std::string getName();
        std::string getSurname();
        std::string getNickname();
        std::string getDarkestSecret();
        std::string getFavoriteMeal();
        std::string getPhoneNumber();
        bool getFlagNotNull();

        /*===================[SETTERS]===================*/
        void setName(std::string valueName);
        void setSurname(std::string valueSurname);
        void setNickname(std::string valueNickname);
        void setDarkestSecret(std::string valueDarkestSecret);
        void setFavoriteMeal(std::string valueFavoriteMeal);
        void setPhoneNumber(std::string valueOtherInfo);
        void setFlagNotNuLL();
};

#endif