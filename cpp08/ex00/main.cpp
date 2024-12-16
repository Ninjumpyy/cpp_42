/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:04:09 by thomas            #+#    #+#             */
/*   Updated: 2024/12/16 15:00:08 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void	test_vector() {
	std::cout << "--- Testing vector ---" << std::endl;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);

	try {
		easyfind(v, 1);
		easyfind(v, 2);
		easyfind(v, 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_list() {
	std::cout << "--- Testing list ---" << std::endl;
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);

	try {
		easyfind(l, 1);
		easyfind(l, 2);
		easyfind(l, 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_deque() {
	std::cout << "--- Testing deque ---" << std::endl;
	std::deque<int> d;
	d.push_back(1);
	d.push_back(2);

	try {
		easyfind(d, 1);
		easyfind(d, 2);
		easyfind(d, 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}


int main() {
	test_vector();
	test_list();
	test_deque();

	return 0;
}
