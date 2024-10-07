/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:35:19 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 18:43:22 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) 
	{
        for (int i = 0; i < 100; ++i) 
        	this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
