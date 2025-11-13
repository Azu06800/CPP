/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:32:54 by nihamdan          #+#    #+#             */
/*   Updated: 2025/07/14 16:32:54 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_issigned;
		int	const			_signrank;
		int	const			_executerank;

	public:
		Form();
		Form(std::string const name, int signrank, int executerank);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName() const;
		bool		getissigned() const;
		int			getsignrank() const;
		int			getexecuterank() const;

		void		beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif
