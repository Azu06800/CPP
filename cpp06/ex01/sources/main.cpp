/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:45:39 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/15 19:49:16 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data d;
    d.id = 42;
    d.name = "Piece_001";

    std::cout << "Original Data:" << std::endl;
    std::cout << "  id = " << d.id << ", name = " << d.name << std::endl;

    uintptr_t raw = Serializer::serialize(&d);

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "\nAfter serialization/deserialization:" << std::endl;
    std::cout << "  id = " << ptr->id << ", name = " << ptr->name << std::endl;

    std::cout << "\nAdresse originale : " << &d << std::endl;
    std::cout << "Adresse après opération : " << ptr << std::endl;

    if (ptr == &d)
        std::cout << "Les pointeurs correspondent !" << std::endl;
    else
        std::cout << "Erreur : pointeurs différents !" << std::endl;

    return 0;
}
