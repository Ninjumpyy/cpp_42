/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:40:13 by thomas            #+#    #+#             */
/*   Updated: 2024/11/13 15:45:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon	 	&_weapon;
		std::string _name;
	
	public:
		//Constructor
		HumanA(std::string name, Weapon &weapon);

		//Destructor
		~HumanA();

		//Methods
		void	attack();
};

#endif