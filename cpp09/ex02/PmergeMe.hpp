/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:11:48 by thomas            #+#    #+#             */
/*   Updated: 2025/01/16 17:23:36 by thomas           ###   ########.fr       */
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
		void print_result(std::vector<int>, std::vector<int>, double, double);
};

#endif