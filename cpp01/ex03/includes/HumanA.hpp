/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:01:20 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/08 19:08:36 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void	attack(void);
	
private:

	std::string _name;
	Weapon &_weapon;
};

#endif