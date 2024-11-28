/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:59:26 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 15:05:27 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		
	public:
		//Constructor
		AMateria(std::string const& type);

		//Copy Constructor
		AMateria(const AMateria& other);

		//Copy Assignment Operator
		AMateria& operator=(const AMateria& other);

		//Destructor
		virtual ~AMateria();

		//Member functions
		std::string const& getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif