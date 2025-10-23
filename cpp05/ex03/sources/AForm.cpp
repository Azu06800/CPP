/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:33:00 by nihamdan          #+#    #+#             */
/*   Updated: 2025/07/14 16:33:00 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("Default"), _issigned(false), _signrank(150), _executerank(150)
{
	std::cout << "Constructor AForm: Default" << std::endl;
}

AForm::AForm(std::string const name, int signrank, int executerank)
{
	if (signrank < 1 || executerank < 1)
		throw AForm::GradeTooHighException();
	if (signrank > 150 || executerank > 150)
		throw AForm::GradeTooLowException();
	this->_name = name;
	this->_issigned = false;
	this->_signrank = signrank;
	this->_executerank = executerank;
	std::cout << "Constructor AForm: " << name << " unsigned with signrank : " << signrank << " and executerank : " << executerank << std::endl;
}

AForm::AForm(const AForm& other)
{
	std::cout << "Copy AForm: " << other._name << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Copy AForm assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_issigned = other.getissigned();
		this->_signrank = other.getsignrank();
		this->_executerank = other.getexecuterank();
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor AForm: " << _name << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool	AForm::getissigned() const
{
	return this->_issigned;
}

int	AForm::getsignrank() const
{
	return this->_signrank;
}

int	AForm::getexecuterank() const
{
	return this->_executerank;
}

void AForm::beSigned(Bureaucrat const & b)
{
	if (this->_signrank < b.getGrade())
		throw AForm::GradeTooLowException();
	this->_issigned = true;
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
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	if (f.getissigned())
		os << f.getName() << ", form is signed, with signrank : " << f.getsignrank() << " and executerank : " << f.getexecuterank() << ".";
	else
		os << f.getName() << ", form is unsigned, with signrank : " << f.getsignrank() << " and executerank : " << f.getexecuterank() << ".";
	return os;
}