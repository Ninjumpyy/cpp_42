/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:43:30 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/29 13:33:18 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _Name;

	public:
		//Constructors
		DiamondTrap();
		DiamondTrap(const std::string &name);

		//Copy Constructor
		DiamondTrap(const DiamondTrap& other);

		//Copy Assignment Operator
		DiamondTrap& operator=(const DiamondTrap& other);
		
		//Destructor
		~DiamondTrap();

		//Member Functions
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif