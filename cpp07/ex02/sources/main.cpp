/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:20:43 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/19 13:21:50 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
	{
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        std::cout << "Contenu de a:" << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> b = a;
        b[0] = 999;
        std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

        Array<std::string> s(3);
        s[0] = "Hello";
        s[1] = "Array";
        s[2] = "Template";
        for (unsigned int i = 0; i < s.size(); i++)
            std::cout << s[i] << std::endl;

        std::cout << a[10] << std::endl;
    }

	catch (std::exception &e)
	{
        std::cerr << "Exception attrapée: " << e.what() << std::endl;
    }
    return 0;
}
