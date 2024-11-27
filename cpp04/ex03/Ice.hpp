/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:38 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 16:42:26 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		//Constructor
		Ice(std::string const& type);

		//Copy Constructor
		Ice(const Ice& other);

		//Copy Assignment Operator
		Ice& operator=(const Ice& other);

		//Destructor
		~Ice();

		//Member functions
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif