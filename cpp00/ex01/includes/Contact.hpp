/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:58:17 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/03 05:08:27 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cctype>
# include <sstream>

class Contact
{
	public:
		
		Contact();
		~Contact();
	
		void first_name();
		void last_name();
		void nickname();
		void phonenumber();
		void darkestsecret();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phonenumber();
		std::string get_darkestsecret();
		int index;
	
	private:
	
		std::string m_first_name;
		std::string m_last_name;
		std::string m_nickname;
		std::string m_phonenumber;
		std::string m_darkestsecret;
		bool isEmptyOrWhitespace(const std::string& str);
};

#endif