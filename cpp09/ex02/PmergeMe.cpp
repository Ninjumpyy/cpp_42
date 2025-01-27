/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:11:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/27 17:32:34 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Constructors
PMergeMe::PMergeMe(): vec(), deq() {}
PMergeMe::PMergeMe(const PMergeMe& other): vec(other.vec), deq(other.deq) {}

//Copy Assignment Operator
PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return (*this);
}

//Destructor
PMergeMe::~PMergeMe() {}

//Method
int PMergeMe::fordjohnson(char **argv)
{
	while (*argv)
	{
		if (!only_digits(*argv)) {
			std::cerr << "Error: positive integer sequence required.\n";
			return (1); //Indicate failure...
		}
		long value = atol(*argv);
		if (value > std::numeric_limits<int>::max()) {
			std::cerr << "Error: out of range.\n";
			return (1); //Indicate failure...
		}
		vec.push_back(value);
		deq.push_back(value);
		argv++;
	}
	
	// Ford-Johnson with a vector container
	clock_t start, end;
	start = clock();
	std::vector<int> vec_sorted = fj_vector(vec, 1);
	end = clock();
	double vectortime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Ford-Johnson with a deque container
	start = clock();
	std::deque<int> deq_sorted = fj_deque(deq, 1);
	end = clock();
	double dequetime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	print_result(vec, vec_sorted, vectortime, dequetime);
	return 0; //Indicate success...
}

//Helpers
bool PMergeMe::only_digits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

std::vector<int> PMergeMe::fj_vector(std::vector<int> vec, int n)
{
	//Step1 : Division into pairs and sorting

	if ((n * 2) > vec.size())
		return vec;
	
	int nb_comp = vec.size() / (n * 2);
	int idx1 = n - 1;
	int idx2 = idx1 + n;

	for (int i = 0; i < nb_comp; i++)
	{
		if (vec[idx2] < vec[idx1])
		{
			std::vector<int>::iterator range1 = vec.begin() + i * n;
			std::vector<int>::iterator range2 = range1 + n;
			std::swap_ranges(range1, range2, range2);
		}

		idx2 += (2 * n);
		idx1 += (2 * n);
	}
	vec = fj_vector(vec, n * 2);

	//Step2 : binary insertion algo

	if (nb_comp == 1)
	{
		if (vec[(n * 2) - 1] < vec[n - 1])
			std::swap_ranges(vec.begin(), vec.begin() + n, vec.begin() + n);
		return vec;
	}

	// Init to_insert
	std::vector<int> to_insert;

	for (int i = (n * 3) - 1; i < vec.size(); i + (2 * n)) {
		to_insert.push_back(vec[i]);
	}

	// Init search
	std::vector<int> search;
	search.push_back(vec[n - 1]);
	for (int i = (n * 2) - 1; i < vec.size(); i + (2 * n)) {
		search.push_back(vec[i]);
	}

	//Init main that will be my new vector
	std::vector<int> main (vec.size());
	std::copy (vec.begin(), vec.begin() + (n * 2), main.begin());

}

std::deque<int> PMergeMe::fj_deque(std::deque<int> deq, int n)
{
	
}

void PMergeMe::print_result(std::vector<int> vec, std::vector<int> vec_sorted, double vectortime, double dequetime)
{
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int>::iterator it = vec_sorted.begin(); it != vec_sorted.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << vectortime << " s\n";
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << dequetime << " s\n";
}
