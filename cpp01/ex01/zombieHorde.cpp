/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:12:59 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/14 20:54:50 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		new (&zombieHorde[i]) Zombie(name);
	}
	return (zombieHorde);
}