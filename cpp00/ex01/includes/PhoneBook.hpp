/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:58:03 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/03 04:50:10 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:

		PhoneBook();
		~PhoneBook();
	
		int nbr_contact;

		void	add_contact(void);
		void	search_contact(void);
		void	show_contact(void);

	private:
		
		int		empty_directory;
		int		flag;
		int		x;
		std::string formatString(const std::string& str, size_t maxLength) const;
		Contact directory[8];
		
};

#endif