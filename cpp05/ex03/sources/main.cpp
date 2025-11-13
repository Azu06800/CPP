/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:34:04 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 16:04:56 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::srand(std::time(NULL));

	try
	{
		Intern someRandomIntern;
		Bureaucrat boss("Alice", 1);

		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}

		std::cout << std::endl;

		AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
		if (shrub)
		{
			boss.signForm(*shrub);
			boss.executeForm(*shrub);
			delete shrub;
		}

		std::cout << std::endl;

		AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
		if (pardon)
		{
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
		}

		std::cout << std::endl;

		// Test erreur
		AForm* unknown = someRandomIntern.makeForm("unknown form", "Nobody");
		if (unknown)
			delete unknown;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
