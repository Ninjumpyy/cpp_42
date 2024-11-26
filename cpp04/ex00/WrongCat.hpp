/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:10:16 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:17:39 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//Constructor
		WrongCat();

		//Copy Constructor
		WrongCat(const WrongCat& other);

		//Copy Assignment Operator
		WrongCat& operator=(const WrongCat& other);

		//Destructor
		~WrongCat();

		//Member function
		void makeSound(void) const;
};

#endif