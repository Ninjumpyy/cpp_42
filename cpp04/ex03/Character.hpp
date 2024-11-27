/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:04 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 17:24:27 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string const& _name;
		AMateria* 	_inventory[4];

	public:
		//Constructor
		Character(std::string const& name);

		//Copy Constructor
		Character(const Character& other);

		//Copy Assignment Operator
		Character& operator=(const Character& other);

		//Destructor
		~Character();

		//Member functions to override
		std::string const& getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif