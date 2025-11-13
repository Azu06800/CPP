/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:14:14 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/09 18:20:55 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::loadDatabase(const std::string& filename)
{
 	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			float rate = std::atof(rateStr.c_str());
			_data[date] = rate;
		}
 	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = std::atoi(date.substr(0,4).c_str());
	int month = std::atoi(date.substr(5,2).c_str());
	int day = std::atoi(date.substr(8,2).c_str());
	return (year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it == _data.end()) // aucune date >=
		--it;
	else if (it->first != date && it != _data.begin())
		--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, valueStr;

		if (!(std::getline(iss, date, '|') && std::getline(iss, valueStr)))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
        }

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value = std::atof(valueStr.c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
 		}

		float rate = getExchangeRate(date);
		std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
	}
	file.close();
}