/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+    +#+          */
/*   Created: 2022/07/07 by jnidorin                   #+#    #+#             */
/*   Updated: 2022/07/07 by jnidorin                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string tmp(argv[i]);
            for (size_t j = 0; j < tmp.length(); j++)
            {
                std::cout << (char)std::toupper(argv[i][j]);
            }
            std::cout << " ";
            
        }
        std::cout << std::endl;
    }
    return 0;
}