/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:52:27 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/16 23:03:36 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(0));
    int r = std::rand() % 3;
    if (r == 0)
		return new A;
    else if (r == 1)
		return new B;
    else
		return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
	catch (std::bad_cast&) {}

    try
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
	catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
catch (std::bad_cast&) {}
}
