/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:41:59 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 15:20:57 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap Gentil("Sirene");
    FragTrap Mechant("Sadique");
    FragTrap Default;

    Gentil.attack("Sadique");
    std::cout << "[TEST PRINCIPAL] Statistique de dégâts [ " << Gentil.getAttackDmg() << " ]" << std::endl << std::endl;

    std::cout << "[TEST PRINCIPAL] Statistique des points de vie AVANT de subir des dégâts [ " << Gentil.getHitPoints() << " ]" << std::endl;
    Gentil.takeDamage(5);
    std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS avoir subi des dégâts [ " << Gentil.getHitPoints() << " ]" << std::endl << std::endl;

    std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie AVANT la réparation [ " << Gentil.getEnergyPoints() << " ]" << std::endl;
    Gentil.beRepaired(2);
    std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS la réparation [ " << Gentil.getHitPoints() << " ]" << std::endl;
    std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie [ " << Gentil.getEnergyPoints() << " ]" << std::endl << std::endl;

    Gentil.highFivesGuys();
    std::cout << std::endl << std::endl;

    Mechant.attack("Sirene");
    std::cout << "[TEST PRINCIPAL] Statistique de dégâts [ " << Mechant.getAttackDmg() << " ]" << std::endl << std::endl;

    std::cout << "[TEST PRINCIPAL] Statistique des points de vie AVANT de subir des dégâts [ " << Default.getHitPoints() << " ]" << std::endl;
    Mechant.takeDamage(3);
    std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS avoir subi des dégâts [ " << Mechant.getHitPoints() << " ]" << std::endl << std::endl;

    std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie AVANT la réparation [ " << Mechant.getEnergyPoints() << " ]" << std::endl;
    Mechant.beRepaired(7);
    std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie APRÈS la réparation [ " << Mechant.getEnergyPoints() << " ]" << std::endl;
    std::cout << "[TEST PRINCIPAL] Statistique des points de vie [ " << Mechant.getHitPoints() << " ]" << std::endl << std::endl;

    Mechant.highFivesGuys();
    std::cout << std::endl << std::endl;

    Default.attack("Random");
    std::cout << "[TEST PRINCIPAL] Statistique de dégâts [ " << Default.getAttackDmg() << " ]" << std::endl << std::endl;

    std::cout << "[TEST PRINCIPAL] Statistique des points de vie AVANT de subir des dégâts [ " << Default.getHitPoints() << " ]" << std::endl;
    Default.takeDamage(4);
    std::cout << "[TEST PRINCIPAL] Statistique des points de vie APRÈS avoir subi des dégâts [ " << Default.getHitPoints() << " ]" << std::endl << std::endl;

    std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie AVANT la réparation [ " << Default.getEnergyPoints() << " ]" << std::endl;
    Default.beRepaired(9);
    std::cout << "[TEST PRINCIPAL] Statistique des points d'énergie APRÈS la réparation [ " << Default.getEnergyPoints() << " ]" << std::endl;
    std::cout << "[TEST PRINCIPAL] Statistique des points de vie [ " << Default.getHitPoints() << " ]" << std::endl << std::endl;

    Default.highFivesGuys();
    std::cout << std::endl << std::endl;

    return (0);
}