/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 01:16:00 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 16:13:45 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string const formName, std::string const target) const
{
	std::string names[3] =
    {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* forms[3] =
    {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;

			for (int j = 0; j < 3; j++) // sup les form non utilisé
			{
				if (i != j)
					delete forms[j];
			}

			return forms[i];
		}
	}

	std::cout << "Intern couldn’t find form \"" << formName << "\"" << std::endl;

	for (int i = 0; i < 3; i++)
		delete forms[i];

	return NULL;
}
