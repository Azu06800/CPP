/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:07:43 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/16 23:07:54 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>

int main() {
    Base* obj = generate();

    std::cout << "Identification via pointeur : ";
    identify(obj);

    std::cout << "Identification via référence : ";
    identify(*obj);

    delete obj;
    return 0;
}
