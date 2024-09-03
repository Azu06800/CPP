/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:37:52 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/03 04:48:11 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string buff;
	PhoneBook phonebook;
	
	std::cout << "Welcome to your PhoneBook menu by nihamdan" << std::endl;
	while(1)
	{
		std::cout << "Enter a command [ADD][SEARCH] or [EXIT]:";
		std::cin >> buff;
	
		if(buff == "ADD")
			phonebook.add_contact();
		else if(buff == "SEARCH")
			phonebook.search_contact();
		else if(buff == "EXIT")
			break;
		else
			std::cout << "invalid command" << std::endl;
	}
	return (0);	
}
