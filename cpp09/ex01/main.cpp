/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:10:17 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 12:10:01 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./RPN [inverted Polish mathematical expression]\n";
		return 0;
	}
	
	RPN obj;
	return obj.print_result_rpn(argv[1]);
}