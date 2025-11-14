/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:42:47 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 22:17:36 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F f)
{
	for (size_t i = 0; i < length; ++i)
		f(array[i]);
}

template <typename T, typename F>
void iter(T const* array, size_t length, F f)
{
	for (size_t i = 0; i < length; ++i)
		f(array[i]); 
}

#endif

