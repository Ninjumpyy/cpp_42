/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:13 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 12:01:47 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* dog_brain;
		
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
		Brain*	getBrain(void) const;
};

#endif