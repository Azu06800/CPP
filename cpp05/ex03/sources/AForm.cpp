/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:33:00 by nihamdan          #+#    #+#             */
/*   Updated: 2025/07/14 16:33:00 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _issigned(false), _signrank(150), _executerank(150) {}

AForm::AForm(std::string const name, int signrank, int executerank) : _name(name), _issigned(false), _signrank(signrank), _executerank(executerank)
{
	if (signrank < 1 || executerank < 1)
		throw GradeTooHighException();
	if (signrank > 150 || executerank > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _issigned(other._issigned), _signrank(other._signrank), _executerank(other._executerank) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_issigned = other._issigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getissigned() const
{
	return _issigned;
}

int AForm::getsignrank() const
{
	return _signrank;
}

int AForm::getexecuterank() const
{
	return _executerank;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signrank)
		throw GradeTooLowException();
	_issigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << b.getName() << ", form "
		<< (b.getissigned() ? "is signed" : "is unsigned")
		<< ", sign rank " << b.getsignrank()
		<< ", execute rank " << b.getexecuterank() << ".";
	return os;
}
