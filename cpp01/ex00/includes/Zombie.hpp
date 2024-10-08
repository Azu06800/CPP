/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:22:40 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/07 21:52:54 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	public:
	
		Zombie(std::string);
		~Zombie();
		void announce(void);

	private:

		std::string _name;	
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);


#endif