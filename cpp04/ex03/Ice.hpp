/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:38 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 11:33:19 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		//Constructor
		Ice();

		//Copy Constructor
		Ice(const Ice& other);

		//Copy Assignment Operator
		Ice& operator=(const Ice& other);

		//Destructor
		~Ice();

		//Member functions to override
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif