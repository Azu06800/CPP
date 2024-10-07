/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:01:49 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/08 18:39:33 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type){}

Weapon::~Weapon(){}

std::string const & Weapon::getType()
{
	std::string const & type = this->_type;
	return(type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
