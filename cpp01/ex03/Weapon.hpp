/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:28:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/13 13:46:04 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string _type;
		
	public:
		//Constructor
		Weapon();
		Weapon(std::string type);

		//Destructor
		~Weapon();

		//Methods
		const std::string	&getType() const;
		void		setType(std::string type);
};

#endif