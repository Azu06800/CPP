/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:05:51 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/09 23:46:53 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "Default constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Constructor ShrubberyCreationForm: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
    std::cout << "Copy constructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "Copy assignment ShrubberyCreationForm" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor ShrubberyCreationForm: " << _target << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!getissigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getexecuterank())
        throw AForm::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "   ^   " << std::endl;
        file << "  /|\\  " << std::endl;
        file << " /|||\\ " << std::endl;
        file << "   |   " << std::endl;
        file.close();
    }
}
