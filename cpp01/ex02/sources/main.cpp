/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:59:28 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/08 16:56:38 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "memory adress of brain : " << &brain << std:: endl;
	std::cout << "memory adress of stringPTR : " << stringPTR << std:: endl;
	std::cout << "memory adress of stringREF : " << &stringREF << std:: endl;

	std::cout << "value of brain : " << brain << std:: endl;
	std::cout << "value pointed by stringPTR : " << *stringPTR << std:: endl;
	std::cout << "value pointed by stringREF : " << stringREF << std:: endl;
	return 0;
}