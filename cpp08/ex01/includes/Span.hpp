/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:32:59 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 23:41:01 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int value);

		template <typename It>
		void addRange(It begin, It end)
		{
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::runtime_error("Capacité dépassée");
			_numbers.insert(_numbers.end(), begin, end);
		}

		int shortestSpan() const;
		int longestSpan() const;
};

#endif
