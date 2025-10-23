/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:34:04 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/10 01:48:55 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;

        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* robo  = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon= someRandomIntern.makeForm("presidential pardon", "Arthur");
        AForm* fail  = someRandomIntern.makeForm("coffee form", "Nobody"); // invalide

        std::cout << std::endl;

        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 20);
        Bureaucrat carol("Carol", 1);

        if (shrub) {
            alice.signForm(*shrub);
            alice.executeForm(*shrub);
        }

        if (robo) {
            alice.signForm(*robo);
            bob.executeForm(*robo);   // OK: Bob grade 20 <= 45
        }

        if (pardon) {
            alice.signForm(*pardon);  // KO (Alice 50 > 25 req)
            carol.signForm(*pardon);  // OK (Carol 1 <= 25)
            carol.executeForm(*pardon); // OK (Carol 1 <= 5)
        }

        delete shrub;
        delete robo;
        delete pardon;
        delete fail;

    } catch (std::exception& e) {
        std::cerr << "Exception caught (top-level): " << e.what() << std::endl;
    }
    return 0;
}
