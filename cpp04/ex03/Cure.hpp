/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:56 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 16:59:59 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		//Constructor
		Cure(std::string const& type);

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