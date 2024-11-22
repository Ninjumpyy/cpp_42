/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:13:05 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/22 17:18:38 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		//Constructor
		FragTrap(const std::string& name);

		//Copy Constructor
		FragTrap(const FragTrap& other);

		//Copy Assignment Operator
		FragTrap& operator=(const FragTrap& other);

		//Destructor
		virtual ~FragTrap();

		//Member Function
		void	highFivesGuys(void);
};

#endif