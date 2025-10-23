/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:44:10 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/17 01:45:03 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const& x)
{
    std::cout << x << std::endl;
}

void incrementInt(int &x)
{
    x++;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Affichage des int:" << std::endl;
    iter(arr, 5, printElement<int>);

    iter(arr, 5, incrementInt);
    std::cout << "Après incrémentation:" << std::endl;
    iter(arr, 5, printElement<int>);

    std::string strs[3] = {"Hello", "World", "!"};
    std::cout << "Affichage des strings:" << std::endl;
    iter(strs, 3, printElement<std::string>);

    return 0;
}
