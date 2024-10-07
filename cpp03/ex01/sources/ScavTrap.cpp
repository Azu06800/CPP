/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:43:47 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 17:04:18 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap "<< _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap "<< _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "Copy ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment ScavTrap (" << _name << ") operator called" << std::endl;
	if (this != &other) 
        ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "<< _name << " destructor called" << std::endl;
}

	
void ScavTrap::attack(const std::string &target)
{
	if(_hitpoints == 0 || _energypoints == 0)
		std::cout << "ScavTrap " << _name << " cannot attack !" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attackdamage << " points of damage !" << std::endl;
		_energypoints--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " enter Gate keeper Mode !" << std::endl;
}
