/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:45:56 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/05 15:58:10 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return(1);
	}
	else
	{
		std::string message = argv[1];
		for (int i = 1; i < argc; i++)
		{
			std::string message = argv[i];
			int j = 0;
			while (message[j])
			{
				if (std::islower(message[j]))
					std::cout << static_cast<char>(std::toupper(message[j]));
				else
					std::cout << message[j];
				j++;
			}
		}
		std::cout << std::endl;
		return (0);
	}
}
