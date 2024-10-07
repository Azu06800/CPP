/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:59:28 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/07 21:58:10 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *Zombieptr = newZombie("James");

	Zombie Zombie0("Joe");
	Zombie0.announce();
	Zombieptr->announce();
	randomChump("Willy");

	delete Zombieptr;
	return 0;
}