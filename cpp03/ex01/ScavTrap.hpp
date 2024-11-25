/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:25:53 by thomas            #+#    #+#             */
/*   Updated: 2024/11/25 11:41:50 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		//Constructors
		ScavTrap();
		ScavTrap(const std::string &name);

		//Copy Constructor
		ScavTrap(const ScavTrap& other);

		//Copy Assignment Operator
		ScavTrap& operator=(const ScavTrap& other);

		//Destructor
		virtual ~ScavTrap();

		//Public Member Functions
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif