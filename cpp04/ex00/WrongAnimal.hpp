/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:15 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:16:39 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		//Constructor
		WrongAnimal();

		//Copy Constructor
		WrongAnimal(const WrongAnimal& other);

		//Copy Assignment Operator
		WrongAnimal& operator=(const WrongAnimal& other);

		//Destructor
		virtual ~WrongAnimal();

		//Member Functions
		void makeSound(void) const;
		std::string getType(void) const;
};

#endif