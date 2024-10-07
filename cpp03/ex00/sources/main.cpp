/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:41:59 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 13:40:24 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Gentil("Steve");
	ClapTrap Mechant("Herobrine");
	ClapTrap Default;

    std::cout << "[TEST PRINCIPAL] Statistiques après la création des ClapTraps :" << std::endl;
    std::cout << "Nom du Gentil : " << Gentil.getName() << std::endl;
    std::cout << "Points de vie de Gentil : " << Gentil.getHitPoints() << std::endl;
    std::cout << "Points d'énergie de Gentil : " << Gentil.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque de Gentil : " << Gentil.getAttackDmg() << std::endl << std::endl;

    std::cout << "Nom du Mechant : " << Mechant.getName() << std::endl;
    std::cout << "Points de vie de Mechant : " << Mechant.getHitPoints() << std::endl;
    std::cout << "Points d'énergie de Mechant : " << Mechant.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque de Mechant : " << Mechant.getAttackDmg() << std::endl << std::endl;

    std::cout << "Nom de Default : " << Default.getName() << std::endl;
    std::cout << "Points de vie de Default : " << Default.getHitPoints() << std::endl;
    std::cout << "Points d'énergie de Default : " << Default.getEnergyPoints() << std::endl;
    std::cout << "Dégâts d'attaque de Default : " << Default.getAttackDmg() << std::endl << std::endl;

	Gentil.attack("Jack");
	std::cout << "[TEST PRINCIPAL] Statistique de dégâts [ " << Gentil.getAttackDmg() << " ]" << std::endl << std::endl;

	std::cout << "[TEST PRINCIPAL] Statistique des points de vie AVANT de prendre des dégâts [ " << Gentil.getHitPoints() << " ]" << std::endl;
	Gentil.takeDamage(5);
	std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS avoir pris des dégâts [ " << Gentil.getHitPoints() << " ]" << std::endl << std::endl;

	std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie AVANT réparation [ " << Gentil.getEnergyPoints() << " ]" << std::endl;
	Gentil.beRepaired(2);
	std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS réparation [ " << Gentil.getHitPoints() << " ]" << std::endl;
	std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie [ " << Gentil.getEnergyPoints() << " ]" << std::endl << std::endl;

	Mechant.attack("Necromancienne");
	std::cout << "[TEST PRINCIPAL] Statistique de dégâts [ " << Mechant.getAttackDmg() << " ]" << std::endl << std::endl;

	std::cout << "[TEST PRINCIPAL] Statistique des points de vie AVANT de prendre des dégâts [ " << Default.getHitPoints() << " ]" << std::endl;
	Mechant.takeDamage(3);
	std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS avoir pris des dégâts [ " << Mechant.getHitPoints() << " ]" << std::endl << std::endl;

	std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie AVANT réparation [ " << Mechant.getEnergyPoints() << " ]" << std::endl;
	Mechant.beRepaired(7);
	std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie APRÈS réparation [ " << Mechant.getEnergyPoints() << " ]" << std::endl;
	std::cout << "[TEST PRINCIPAL] Statistique des points de vie [ " << Mechant.getHitPoints() << " ]" << std::endl << std::endl;


	Default.attack("Random");
	std::cout << "[TEST PRINCIPAL] Statistique de dégâts [ " << Default.getAttackDmg() << " ]" << std::endl << std::endl;

	std::cout << "[TEST PRINCIPAL] Statistique des points de vie AVANT de prendre des dégâts [ " << Default.getHitPoints() << " ]" << std::endl;
	Default.takeDamage(4);
	std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS avoir pris des dégâts [ " << Default.getHitPoints() << " ]" << std::endl << std::endl;

	std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie AVANT réparation [ " << Default.getEnergyPoints() << " ]" << std::endl;
	Default.beRepaired(9);
	std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie APRÈS réparation [ " << Default.getEnergyPoints() << " ]" << std::endl;
	std::cout << "[TEST PRINCIPAL] Statistique des points de vie [ " << Default.getHitPoints() << " ]" << std::endl << std::endl;

	return(0);
}