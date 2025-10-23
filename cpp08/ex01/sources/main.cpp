/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:51:22 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/19 20:52:40 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
	{
        std::cout << "=== Test du sujet ===" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;


        std::cout << "\n=== Test exceptions ===" << std::endl;
        try
		{
            sp.addNumber(42);
        }
		catch (std::exception& e)
		{
            std::cout << "Erreur: " << e.what() << std::endl;
        }

        Span sp2(2);
        sp2.addNumber(10);
        try
		{
            std::cout << sp2.shortestSpan() << std::endl;
        }
		catch (std::exception &e)
		{
            std::cout << "Erreur: " << e.what() << std::endl;
        }


        std::cout << "\n=== Test avec 10000 nombres (addNumber) ===" << std::endl;
        Span big(10000);
        for (int i = 0; i < 10000; i++)
            big.addNumber(i * 2);

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span: " << big.longestSpan() << std::endl;


        std::cout << "\n=== Test avec addRange ===" << std::endl;
        Span sp3(6);
        std::vector<int> vec;
		vec.push_back(100);
		vec.push_back(105);
		vec.push_back(110);
		vec.push_back(200);
		vec.push_back(1000);
		vec.push_back(1010);

		sp3.addRange(vec.begin(), vec.end());

        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

    } catch (std::exception& e)
	{
        std::cerr << "Erreur générale: " << e.what() << std::endl;
    }

    return 0;
}
