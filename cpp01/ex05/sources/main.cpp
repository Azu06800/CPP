/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:57:17 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/11 18:12:17 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl Harl;
    std::string level;

    while (1) 
	{
        std::cout << "Choose a level of complain: ";
	    std::getline(std::cin, level);
        if (std::cin.fail())
            exit(1);
        Harl.complain(level);
    }
}