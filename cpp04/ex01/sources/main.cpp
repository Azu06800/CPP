/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:30:38 by nihamdan          #+#    #+#             */
/*   Updated: 2024/10/07 19:10:26 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    j->makeSound();
    i->makeSound();

    const WrongAnimal* m = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();
    std::cout << m->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    m->makeSound();
    k->makeSound();

    delete i;
    delete j;
    delete meta;

    const Animal *tab[10];
    for (int i = 0; i <= 10; i++) {
        if (i % 2 == 0)
            tab[i] = new Dog();
        else
            tab[i] = new Cat();
    }

    for (int i = 0; i <= 10; i++) {
        delete tab[i];
    }

    Cat cat;
    cat.getType();
    cat.makeSound();
    return 0;
}