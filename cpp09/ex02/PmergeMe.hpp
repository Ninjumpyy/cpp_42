/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:11:48 by thomas            #+#    #+#             */
/*   Updated: 2025/01/28 11:31:27 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <limits>
# include <cstdlib>
# include <time.h>
# include <algorithm>
# include <iomanip> 
# include <iterator>
# include <cmath>


class PMergeMe
{
	public:
		//Constructors
		PMergeMe();
		PMergeMe(const PMergeMe& other);

		//Copy Assignment Operator
		PMergeMe& operator=(const PMergeMe& other);

		//Destructor
		~PMergeMe();

		//Method
		int fordjohnson(char **argv);

	private:
		std::vector<int> vec;
		std::deque<int>  deq;

		//Helpers
		bool only_digits(std::string);
		std::vector<int> fj_vector(std::vector<int>, int);
		std::deque<int> fj_deque(std::deque<int>, int);
		int jacobsthal_number(int k);
		void print_result(std::vector<int>, std::vector<int>, double, double);
};

#endif