/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:49:14 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 17:04:38 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "FragTrap "<< _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "FragTrap "<< _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Copy FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy assignment FragTrap (" << _name << ") operator called" << std::endl;
	if (this != &other) 
        ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< _name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if(_hitpoints == 0 || _energypoints == 0)
		std::cout << "FragTrap " << _name << " cannot attack !" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attack " << target << ", causing " << _attackdamage << " points of damage !" << std::endl;
		_energypoints--;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "<< _name << " want to high fives !" << std::endl;
}