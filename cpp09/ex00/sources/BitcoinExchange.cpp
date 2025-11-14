/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:14:14 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/14 01:05:14 by nihamdan         ###   ########.fr       */
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

std::string BitcoinExchange::trim(const std::string& s)
{
	std::string::size_type a = s.find_first_not_of(" \t\r\n");
	if (a == std::string::npos)
		return "";
	std::string::size_type b = s.find_last_not_of(" \t\r\n");
	return s.substr(a, b - a + 1);
}

bool BitcoinExchange::isDigits(const std::string& s)
{
	for (std::string::size_type i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

bool BitcoinExchange::isBisextil(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string sy = date.substr(0, 4);
	std::string sm = date.substr(5, 2);
	std::string sd = date.substr(8, 2);

	if (!isDigits(sy) || !isDigits(sm) || !isDigits(sd))
		return false;

	int year = std::atoi(sy.c_str());
	int month = std::atoi(sm.c_str());
	int day = std::atoi(sd.c_str());

	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;

	int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isBisextil(year))
		mdays[1] = 29;

	if (day < 1 || day > mdays[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::parseStrictDouble(const std::string& s, double& out)
{
	char* end = 0;
	const char* cs = s.c_str();
	out = std::strtod(cs, &end);
	if (end == cs)
		return false;
	while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n')
		++end;
	return (*end == '\0');
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;

	if (std::getline(file, line))
	{
		if (line.find(',') != std::string::npos && line.find("date") == std::string::npos)
		{
			std::istringstream iss(line);
			std::string date, rateStr;
			if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
			{
				date = trim(date);
				rateStr = trim(rateStr);
				double rate;
				if (isValidDate(date) && parseStrictDouble(rateStr, rate))
					_data[date] = rate;
			}
		}
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::istringstream iss(line);
		std::string date, rateStr;
		if (!(std::getline(iss, date, ',') && std::getline(iss, rateStr)))
			continue;

		date = trim(date);
		rateStr = trim(rateStr);

		double rate;
		if (!isValidDate(date))
			continue;
		if (!parseStrictDouble(rateStr, rate))
			continue;

		_data[date] = rate;
	}

	file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	if (_data.empty())
		throw std::runtime_error("Error: empty database.");

	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

	if (it == _data.end())
	{
		--it;
		return it->second;
	}

	if (it->first == date)
		return it->second;

	if (it == _data.begin())
		throw std::runtime_error("Error: no earlier date in database.");

	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;

	if (std::getline(file, line))
	{
		if (line.find('|') == std::string::npos)
			file.seekg(0);
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string raw = line;

		std::string date;
		std::string valueStr;

		std::string::size_type bar = line.find('|');
		if (bar == std::string::npos)
		{
			std::cerr << "Error: bad input => " << raw << std::endl;
			continue;
		}

		date = trim(line.substr(0, bar));
		valueStr = trim(line.substr(bar + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << raw << std::endl;
			continue;
		}

		double value;
		if (!parseStrictDouble(valueStr, value))
		{
			std::cerr << "Error: bad input => " << raw << std::endl;
			continue;
		}
		if (value < 0.0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	file.close();
}
