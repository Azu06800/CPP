/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:05:51 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 15:44:11 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getissigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getexecuterank())
		throw GradeTooLowException();

	std::ofstream file((_target + "_shrubbery").c_str());
	file << "       _-_       \n"
	        "    /~~   ~~\\   \n"
	        " /~~         ~~\\ \n"
	        "{               }\n"
	        " \\  _-     -_  / \n"
	        "   ~  \\\\ //  ~  \n"
	        "_- -   | | _- _  \n"
	        "  _ -  | |   -_  \n"
	        "      // \\\\      \n";
	file.close();
}
