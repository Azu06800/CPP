/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:26:12 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:58 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CPP
# define FIXED_CPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int 	_fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed& operator=(const Fixed &other);

		bool operator>(const Fixed& other) const;
    	bool operator<(const Fixed& other) const;
    	bool operator>=(const Fixed& other) const;
    	bool operator<=(const Fixed& other) const;
    	bool operator==(const Fixed& other) const;
    	bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
    	Fixed operator-(const Fixed& other) const;
    	Fixed operator*(const Fixed& other) const;
    	Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
    	Fixed operator++(int);
    	Fixed& operator--();
    	Fixed operator--(int);
		
		static Fixed& min(Fixed& a, Fixed& b);
    	static const Fixed& min(const Fixed& a, const Fixed& b);
    	static Fixed& max(Fixed& a, Fixed& b);
    	static const Fixed& max(const Fixed& a, const Fixed& b);
		
		float 	toFloat(void) const;
		int 	toInt(void) const;
		
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif