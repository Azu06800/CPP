/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:37:43 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/03 03:50:12 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact() {}

bool Contact::isEmptyOrWhitespace(const std::string& str) 
{
    if (str.empty()) {
        return true;
    }
    size_t i = 0;
    while (i < str.size()) {
        if (!std::isspace(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

void Contact::first_name()
{
	while(1)
	{
		std::cout << "Enter a first name:";
		std::getline(std::cin, m_first_name);
		if (isEmptyOrWhitespace(m_first_name))
			std::cout << "Cannot be empty" << std::endl;
		else
			break;
	}
	return;
}

void Contact::last_name()
{
	while(1)
	{
		std::cout << "Enter a last name:";
		std::getline(std::cin, m_last_name);
		if (!isEmptyOrWhitespace(m_last_name))
			break;
		else
			std::cout << "Cannot be empty" << std::endl;
	}
	return;
}

void Contact::nickname()
{
	while(1)
	{
		std::cout << "Enter a nickname:";
		std::getline(std::cin, m_nickname);
		if (!isEmptyOrWhitespace(m_nickname))
			break;
		else
			std::cout << "Cannot be empty" << std::endl;
	}
	return;
}

void Contact::phonenumber()
{
	while(1)
	{
		std::cout << "Enter a phone number:";
		std::getline(std::cin, m_phonenumber);
		if (!isEmptyOrWhitespace(m_phonenumber))
			break;
		else
			std::cout << "Cannot be empty" << std::endl;
	}
	return;
}

void Contact::darkestsecret()
{
	while(1)
	{
		std::cout << "Enter a darkest secret:";
		std::getline(std::cin, m_darkestsecret);
		if (!isEmptyOrWhitespace(m_darkestsecret))
			break;
		else
			std::cout << "Cannot be empty" << std::endl;
	}
	return;
}

std::string Contact::get_first_name()
{
	return (m_first_name);
}

std::string Contact::get_last_name()
{
	return (m_last_name);
}

std::string Contact::get_nickname()
{
	return (m_nickname);
}
std::string Contact::get_phonenumber()
{
	return (m_phonenumber);
}

std::string Contact::get_darkestsecret()
{
	return (m_darkestsecret);
}
