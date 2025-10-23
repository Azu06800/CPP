/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:05:40 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/09 23:46:40 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "Default constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Constructor PresidentialPardonForm: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target)
{
    std::cout << "Copy constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "Copy assignment PresidentialPardonForm" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor PresidentialPardonForm: " << _target << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!getissigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getexecuterank())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
