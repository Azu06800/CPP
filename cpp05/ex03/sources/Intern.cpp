/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 01:16:00 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/10 01:50:42 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static AForm* createShrubbery(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
	std::cout << "Constructor Intern" << std::endl;
}

Intern::Intern(const Intern&)
{
	std::cout << "Copy constructor Intern" << std::endl;
}

Intern& Intern::operator=(const Intern&)
{
	std::cout << "Copy assignment Intern" << std::endl; return *this;
}

Intern::~Intern()
{
	std::cout << "Destructor Intern" << std::endl;
}

AForm* Intern::makeForm(std::string const & formName, std::string const & target) const
{
    const std::string names[3] =
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(std::string const &) =
	{
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; ++i)
	{
        if (formName == names[i])
		{
            AForm* f = creators[i](target);
            std::cout << "Intern creates " << f->getName() << std::endl;
            return f;
        }
    }

    std::cout << "Intern: error: unknown form name \"" << formName
              << "\". Available: \"shrubbery creation\", "
                 "\"robotomy request\", \"presidential pardon\"."
              << std::endl;
    return 0;
}
