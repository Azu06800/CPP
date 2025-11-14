/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:03:10 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 21:23:12 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter&)
{
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& s)
{
	return (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff");
}

static bool isChar(const std::string& s)
{
	return (s.size() == 1 && !std::isdigit(s[0]));
}

static bool isInt(const std::string& s)
{
	char *end;
	std::strtol(s.c_str(), &end, 10);
	return (*end == '\0');
}

static bool isFloat(const std::string& s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;
	char *end;
	std::strtof(s.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	char *end;
	std::strtod(s.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convert(std::string const& s)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isPseudoLiteral(s))
	{
		if (s == "nan" || s == "nanf")
		{
			std::cout << "char: impossible\nint: impossible\n";
			std::cout << "float: nanf\ndouble: nan\n";
		}
		else if (s == "+inf" || s == "+inff")
		{
			std::cout << "char: impossible\nint: impossible\n";
			std::cout << "float: +inff\ndouble: +inf\n";
		}
		else if (s == "-inf" || s == "-inff")
		{
			std::cout << "char: impossible\nint: impossible\n";
			std::cout << "float: -inff\ndouble: -inf\n";
		}
		return;
	}

	if (isChar(s))
	{
		char c = s[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return;
	}

	if (isInt(s))
	{
		long l = std::strtol(s.c_str(), 0, 10);
		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
			return;
		}
		int i = static_cast<int>(l);

		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'\n";
		else
			std::cout << "char: Non displayable\n";

		std::cout << "int: " << i << "\n";
		std::cout << "float: " << static_cast<float>(i) << "f\n";
		std::cout << "double: " << static_cast<double>(i) << "\n";
		return;
	}

	if (isFloat(s))
	{
		float f = std::strtof(s.c_str(), 0);

		if (std::isnan(f) || std::isinf(f))
			std::cout << "char: impossible\nint: impossible\n";
		else if (f >= 32 && f <= 126)
			std::cout << "char: '" << static_cast<char>(f) << "'\nint: " << static_cast<int>(f) << "\n";
		else
			std::cout << "char: Non displayable\nint: " << static_cast<int>(f) << "\n";

		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
		return;
	}

	if (isDouble(s))
	{
		double d = std::strtod(s.c_str(), 0);

		if (std::isnan(d) || std::isinf(d))
			std::cout << "char: impossible\nint: impossible\n";
		else if (d >= 32 && d <= 126)
			std::cout << "char: '" << static_cast<char>(d) << "'\nint: " << static_cast<int>(d) << "\n";
		else
			std::cout << "char: Non displayable\nint: " << static_cast<int>(d) << "\n";

		std::cout << "float: " << static_cast<float>(d) << "f\n";
		std::cout << "double: " << d << "\n";
		return;
	}

	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}
