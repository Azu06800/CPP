/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:33:00 by nihamdan          #+#    #+#             */
/*   Updated: 2025/07/14 16:33:00 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"), _issigned(false), _signrank(150), _executerank(150)
{
	std::cout << "Constructor Form: Default" << std::endl;
}

Form::Form(std::string const name, int signrank, int executerank)
{
	if (signrank < 1 || executerank < 1)
		throw Form::GradeTooHighException();
	if (signrank > 150 || executerank > 150)
		throw Form::GradeTooLowException();
	this->_name = name;
	this->_issigned = false;
	this->_signrank = signrank;
	this->_executerank = executerank;
	std::cout << "Constructor Form: " << name << " unsigned with signrank : " << signrank << " and executerank : " << executerank << std::endl;
}

Form::Form(const Form& other)
{
	std::cout << "Copy Form: " << other._name << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Copy Form assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_issigned = other.getissigned();
		this->_signrank = other.getsignrank();
		this->_executerank = other.getexecuterank();
	}
	return *this;

}

Form::~Form()
{
	std::cout << "Destructor Form: " << _name << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getissigned() const
{
	return this->_issigned;
}

int	Form::getsignrank() const
{
	return this->_signrank;
}

int	Form::getexecuterank() const
{
	return this->_executerank;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if(this->_signrank < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_issigned = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	if (b.getissigned() == true)
		os << b.getName() << ", form is signed, with signrank : " << b.getsignrank() << " and executerank : " << b.getexecuterank() << ".";
	else
		os << b.getName() << ", form is unsigned, with signrank : " << b.getsignrank() << " and executerank : " << b.getexecuterank() << ".";
    return os;
}