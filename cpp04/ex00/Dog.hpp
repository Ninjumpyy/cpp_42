/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:13 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:15:09 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		//Constructor
		Dog();

		//Copy Constructor
		Dog(const Dog& other);

		//Copy Assignment Operator
		Dog& operator=(const Dog& other);

		//Destructor
		~Dog();

		//Member function
		void makeSound(void) const;
};

#endif