/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:22:40 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/07 22:38:29 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	public:
	
		Zombie();
		~Zombie();
		void announce(void);
		void setName(std::string);
		
	private:

		std::string _name;	
};

Zombie* zombieHorde(int N, std::string name);

#endif