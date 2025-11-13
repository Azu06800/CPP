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

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _issigned(false), _signrank(150), _executerank(150) {}

Form::Form(std::string const name, int signrank, int executerank) : _name(name), _issigned(false), _signrank(signrank), _executerank(executerank)
{
	if (signrank < 1 || executerank < 1)
		throw GradeTooHighException();
	if (signrank > 150 || executerank > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _issigned(other._issigned), _signrank(other._signrank), _executerank(other._executerank) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_issigned = other._issigned;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return _name;
}

bool Form::getissigned() const
{
	return _issigned;
}

int Form::getsignrank() const
{
	return _signrank;
}

int Form::getexecuterank() const
{
	return _executerank;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signrank)
		throw GradeTooLowException();
	_issigned = true;
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
	os << b.getName() << ", form "
	   << (b.getissigned() ? "is signed" : "is unsigned")
	   << ", sign rank " << b.getsignrank()
	   << ", execute rank " << b.getexecuterank() << ".";
	return os;
}
