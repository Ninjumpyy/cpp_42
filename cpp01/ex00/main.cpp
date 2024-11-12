/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:54:40 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/12 17:03:06 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie*	heap_zombie = newZombie("HeapZombie");
	heap_zombie->announce();
	delete(heap_zombie);

	randomChump("StackZombie");

	return (0);
}