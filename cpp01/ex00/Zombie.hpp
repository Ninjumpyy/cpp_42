/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:54:59 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/12 16:43:09 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE HPP

#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		//Constructor
		Zombie();
		Zombie(std::string zombie_name);
		//Destructor
		~Zombie();
		
		//Functions or Methods
		void	announce(void);
};

#endif
