/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:58:53 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/03 05:24:54 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nbr_contact = 0;
	flag = 0;
	x = 0;
	empty_directory = 1;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact()
{
	if(empty_directory)
		empty_directory = 0;
	if(nbr_contact > 7)
	{
		nbr_contact = 0;
		flag = 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	directory[nbr_contact].first_name();
	directory[nbr_contact].last_name();
	directory[nbr_contact].nickname();
	directory[nbr_contact].phonenumber();
	directory[nbr_contact].darkestsecret();
	nbr_contact++;
}

std::string PhoneBook::formatString(const std::string& str, size_t maxLength) const 
{
    if (str.length() > maxLength) {
        return str.substr(0, maxLength - 1) + ".";
    }
    return str;
}
void	PhoneBook::show_contact(void)
{
	std::string temp;
	int 		i = -1;
	int			j;
	while(1)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Select an index[1-8]:";
		std::getline(std::cin, temp);
		std::istringstream iss(temp);
		iss >> j;
		if((!flag && j > nbr_contact) || j < 1 || j > 8)
		{
			std::cout << "Bad index, return to main menu" << std::endl;
			return;
		}
		if(flag)
		{
			while(++i < 8)
			{
				if(directory[i].index == j)
				{
					std::cout << "First Name : " << directory[i].get_first_name() << std::endl;
					std::cout << "Last Name : " << directory[i].get_last_name() << std::endl;
					std::cout << "Nickname : " << directory[i].get_nickname() << std::endl;
					std::cout << "Phone Number : " << directory[i].get_phonenumber() << std::endl;
					std::cout << "Darkest Secret : " << directory[i].get_darkestsecret() << std::endl;
					return;
				}
			}
		}
		else
		{
			while(++i < nbr_contact)
			{
				if(directory[i].index == j)
				{
					std::cout << "First Name : " << directory[i].get_first_name() << std::endl;
					std::cout << "Last Name : " << directory[i].get_last_name() << std::endl;
					std::cout << "Nickname : " << directory[i].get_nickname() << std::endl;
					std::cout << "Phone Number : " << directory[i].get_phonenumber() << std::endl;
					std::cout << "Darkest Secret : " << directory[i].get_darkestsecret() << std::endl;
					return;
				}
			}
		}
	}
	
}

void	PhoneBook::search_contact()
{
	if(empty_directory)
	{
		std::cout << "Directory is empty !" << std::endl;
		return;
	}
	std::cout << " ------------------------------------------------ " << std::endl;
    std::cout << "| " << std::setw(6) << std::right << "Index" 
              << " | " << std::setw(10) << std::right << "First Name" 
              << " | " << std::setw(10) << std::right << "Last Name" 
              << " | " << std::setw(10) << std::right << "Nickname" 
              << " |" << std::endl;
    std::cout << " ------------------------------------------------ " << std::endl;
	if(flag)
	{
		while(++x <= 8)
		{
			directory[x-1].index = x;
			std::cout << "| " << std::setw(6) << std::right << x 
                  << " | " << std::setw(10) << std::right << formatString(directory[x-1].get_first_name(), 10) 
                  << " | " << std::setw(10) << std::right << formatString(directory[x-1].get_last_name(), 10) 
                  << " | " << std::setw(10) << std::right << formatString(directory[x-1].get_nickname(), 10) 
                  << " |" << std::endl;
    	}
    std::cout << " ----------------------------------------------- " << std::endl;
	x = 0;
	}
	else
	{
		while(++x <= nbr_contact)
		{
			directory[x-1].index = x;
			std::cout << "| " << std::setw(6) << std::right << x
                  << " | " << std::setw(10) << std::right << formatString(directory[x-1].get_first_name(), 10) 
                  << " | " << std::setw(10) << std::right << formatString(directory[x-1].get_last_name(), 10) 
                  << " | " << std::setw(10) << std::right << formatString(directory[x-1].get_nickname(), 10) 
                  << " |" << std::endl;
    	}
    std::cout << " ------------------------------------------------ " << std::endl;
	x = 0;
	}
	show_contact();
}

