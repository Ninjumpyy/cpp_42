/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:13:14 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/12 17:37:39 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	Zombie*	my_horde = zombieHorde(10, "Asma");
	for (int i = 0; i < 10; i++)
	{
		my_horde[i].announce();
	}
	delete[] my_horde;
	my_horde = NULL;

	return (0);
}
