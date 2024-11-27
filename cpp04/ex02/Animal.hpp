/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:32:45 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 14:49:23 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string type;
	
	public:
		//Constructor
		Animal();

		//Copy Constructor
		Animal(const Animal& other);

		//Copy Assignment Operator
		Animal& operator=(const Animal& other);

		//Destructor
		virtual ~Animal();

		//Virtual Function making it abstract class
		virtual void makeSound(void) const = 0;

		//Member Function
		std::string getType(void) const;
};

#endif