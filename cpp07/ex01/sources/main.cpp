/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:44:10 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 22:24:21 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElem(T const& x)
{
	std::cout << x << std::endl;
}

void inc(int& x)
{
	++x;
}

int main()
{
	int a[] = {1,2,3};
	iter(a, 3, inc);
	iter(a, 3, printElem<int>);

	int const b[] = {10, 20, 30};
	//iter(b, 3, inc);							//ne compile pas
	iter(b, 3, printElem<int>);

	std::string const s[] = {"Salut","Coucou"};
	iter(s, 2, printElem<std::string>);

	return 0;
}
