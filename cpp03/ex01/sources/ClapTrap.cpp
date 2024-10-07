/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:42:10 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 14:42:03 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unamed"), _hitpoints(100), _energypoints(50), _attackdamage(20)
{
	std::cout << "ClapTrap "<< _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(100), _energypoints(50), _attackdamage(20)
{
	std::cout << "ClapTrap "<< _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy ClapTrap " << _name << " constructor called" << std::endl;
	*this=other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment ClapTrap(" << _name << ") operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackdamage = other._attackdamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(_hitpoints == 0 || _energypoints == 0)
		std::cout << "ClapTrap " << _name << " cannot attack !" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackdamage << " points of damage !" << std::endl;
		_energypoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoints == 0)
		std::cout << "ClapTrap " << _name << " is already dead !" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " is hit for " << amount << " points of damage !" << std::endl;
		_hitpoints -= amount;
		if(_hitpoints == 0)
			std::cout << "ClapTrap " << _name << " die !" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hitpoints == 0 || _energypoints == 0)
		std::cout << "ClapTrap " << _name << " cannot repair itself !" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " repair itself for "  << amount << " hp !" << std::endl;
		_hitpoints += amount;
		if (_hitpoints > 100)
			_hitpoints = 100;
		_energypoints--;
	}
}

std::string    ClapTrap::getName(void) const
{
    return (_name);
}

unsigned int    ClapTrap::getHitPoints(void) const
{
    return (_hitpoints);
}

unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return (_energypoints);
}

unsigned int    ClapTrap::getAttackDmg(void) const
{
    return (_attackdamage);
}