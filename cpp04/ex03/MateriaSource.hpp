/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:23:16 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 17:43:35 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		//Constructor
		MateriaSource();

		//Copy Constructor
		MateriaSource(const MateriaSource& other);
		//Copy Assignment Operator

		//Destructor

		//Member functions to override
};

#endif