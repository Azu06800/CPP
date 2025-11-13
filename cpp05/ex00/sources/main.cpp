/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:34:04 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 15:02:37 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
 	{
 		Bureaucrat b1("Alice", 2);
 		std::cout << b1 << std::endl;

 		b1.incrementGrade();
 		std::cout << b1 << std::endl;

		b1.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
		std::cout << b2 << std::endl;

 		b2.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Charlie", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("Léa", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}