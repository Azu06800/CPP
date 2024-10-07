/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:01:36 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/08 19:16:36 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{

public:

	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon& weapon);
	void	attack(void);
	
private:

	std::string _name;
	Weapon* _weapon;
};

#endif