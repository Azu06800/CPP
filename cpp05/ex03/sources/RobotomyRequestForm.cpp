/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:05:43 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/09 23:46:46 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "Default constructor RobotomyRequestForm" << std::endl;
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Constructor RobotomyRequestForm: " << target << std::endl;
    srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target)
{
    std::cout << "Copy constructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "Copy assignment RobotomyRequestForm" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor RobotomyRequestForm: " << _target << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getissigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getexecuterank())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
