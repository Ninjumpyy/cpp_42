/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:40:56 by thomas            #+#    #+#             */
/*   Updated: 2024/11/13 15:45:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon 		*_weapon;
		std::string _name;
	
	public:
		//Constructor
		HumanB(std::string name);

		//Destructor
		~HumanB();

		//Methods
		void	setWeapon(Weapon &weapon);
		void	attack();
};

#endif