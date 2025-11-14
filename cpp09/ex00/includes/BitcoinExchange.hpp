/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:11:27 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/14 01:04:38 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

		static std::string trim(const std::string& s);
		static bool isDigits(const std::string& s);
		static bool isValidDate(const std::string& date);
		static bool isBisextil(int year);
		static bool parseStrictDouble(const std::string& s, double& out);

		double getExchangeRate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void processInput(const std::string& filename) const;
};

#endif
