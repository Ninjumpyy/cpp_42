/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:23:16 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 15:06:36 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* 	_templates[4];
		
	public:
		//Constructor
		MateriaSource();

		//Copy Constructor
		MateriaSource(const MateriaSource& other);

		//Copy Assignment Operator
		MateriaSource& operator=(const MateriaSource& other);

		//Destructor
		~MateriaSource();

		//Member functions to override
		void	learnMateria(AMateria* model);
		AMateria*	createMateria(std::string const& type);
};	

#endif