/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:33:40 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:15:00 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		//Constructor
		Cat();

		//Copy Constructor
		Cat(const Cat& other);

		//Copy Assignment Operator
		Cat& operator=(const Cat& other);

		//Destructor
		~Cat();

		//Member function
		void makeSound(void) const;
};

#endif