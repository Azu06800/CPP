/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:07:43 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/13 21:44:12 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(0));

	Base* obj = generate();

	std::cout << "avec pointeur : ";
	identify(obj);

	std::cout << "avec réf : ";
	identify(*obj);

	delete obj;
	return 0;
}

