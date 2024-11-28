/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:56 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 11:37:48 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		//Constructor
		Cure();

		//Copy Constructor
		Cure(const Cure& other);

		//Copy Assignment Operator
		Cure& operator=(const Cure& other);

		//Destructor
		~Cure();

		//Member functions to override
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif