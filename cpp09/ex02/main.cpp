/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:28 by thomas            #+#    #+#             */
/*   Updated: 2025/01/16 14:43:30 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe [positive integer sequence]\n";
		return 1;
	}

	PMergeMe obj;
	return obj.fordjohnson(++argv);
}