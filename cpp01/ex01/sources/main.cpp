/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:59:28 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/07 22:40:06 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *Horde = zombieHorde(7, "Jarvis");
	
	for(int i = 0; i < 7; i++)
		Horde[i].announce();
	delete []Horde;
	return 0;
}