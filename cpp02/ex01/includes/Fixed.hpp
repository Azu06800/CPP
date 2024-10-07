/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:26:12 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/03 20:40:20 by nihamdan         ###   ########.fr       */
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
		Fixed(const Fixed &other);
		~Fixed();

		Fixed& operator=(const Fixed &other);

		float 	toFloat(void) const;
		int 	toInt(void) const;
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif