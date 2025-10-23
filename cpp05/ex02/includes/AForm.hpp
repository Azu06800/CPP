/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:32:54 by nihamdan          #+#    #+#             */
/*   Updated: 2025/07/14 16:32:54 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat;

class AForm
{
private:
    std::string  _name;
    bool         _issigned;
    int          _signrank;
    int          _executerank;

public:
    AForm();
    AForm(std::string const name, int signrank, int executerank);
    AForm(const AForm& other);
    AForm & operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool        getissigned() const;
    int         getsignrank() const;
    int         getexecuterank() const;

    void beSigned(Bureaucrat const& b);

    virtual void execute(Bureaucrat const& executor) const = 0;

    class GradeTooHighException : public std::exception
	{
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
	{
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
	{
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream & os, AForm const& f);

#endif