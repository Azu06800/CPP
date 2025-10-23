/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:12:21 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/19 16:13:21 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    try
	{
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Trouvé dans vector: " << *it << std::endl;

        std::list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);

        std::list<int>::iterator it2 = easyfind(l, 4);
        std::cout << "Trouvé dans list: " << *it2 << std::endl;

    }
	catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
