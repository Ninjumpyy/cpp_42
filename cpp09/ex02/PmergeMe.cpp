/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:11:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/29 10:58:40 by tle-moel         ###   ########.fr       */
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
	double vectortime = 1000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Ford-Johnson with a deque container
	start = clock();
	std::deque<int> deq_sorted = fj_deque(deq, 1);
	end = clock();
	double dequetime =  1000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;

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

	if ((n * 2) > static_cast<int>(vec.size()))
		return vec;
	
	int nb_comp = static_cast<int>(vec.size()) / (n * 2);
	int idx1 = n - 1;
	int idx2 = idx1 + n;

	for (int i = 0; i < nb_comp; i++)
	{
		if (vec[idx2] < vec[idx1])
		{
			std::vector<int>::iterator range1 = vec.begin() + (2 * n * i);
			std::vector<int>::iterator range2 = range1 + n;
			std::swap_ranges(range1, range2, range2);
		}

		idx2 += (2 * n);
		idx1 += (2 * n);
	}
	vec = fj_vector(vec, n * 2);

	//Step2 : binary insertion algo

	// Init to_insert
	std::vector<int> to_insert;

	for (int i = n - 1; i < static_cast<int>(vec.size()); i += (2 * n)) {
		to_insert.push_back(vec[i]);
	}

	// Init search
	std::vector<int> search;
	search.push_back(vec[n - 1]);
	for (int i = (n * 2) - 1; i < static_cast<int>(vec.size()); i += (2 * n)) {
		search.push_back(vec[i]);
	}

	//Init new_vec that will be my new vector
	std::vector<int> new_vec;
	new_vec.insert(new_vec.end(), vec.begin(), vec.begin() + (n * 2));
	for (int i = (n * 3); (i + n - 1) < static_cast<int>(vec.size()); i += (2 * n)) {
		std::copy (vec.begin() + i, vec.begin() + i + n, std::back_inserter(new_vec));
	}

	//Binary insertion
	int k = 2;

	while (jacobsthal_number(k) <= static_cast<int>(to_insert.size()))
	{
		int i = jacobsthal_number(k);
		while (i > jacobsthal_number(k-1))
		{
			std::vector<int>::iterator it = std::lower_bound(search.begin(), search.begin() + (pow(2, k) - 1), to_insert[i - 1]);
			int index = it - search.begin();
			int range = 2 * (i - 1) * n;

			search.insert(search.begin() + index, to_insert[i - 1]);
			new_vec.insert(new_vec.begin() + (index * n), vec.begin() + range, vec.begin() + range + n);

			i--;
		}
		k++;
	}


	int i = to_insert.size();
	while (i > jacobsthal_number(k-1))
	{
		std::vector<int>::iterator it = std::lower_bound(search.begin(), search.end(), to_insert[i - 1]);
		int index = it - search.begin();
		int range = 2 * (i - 1) * n;
		search.insert(search.begin() + index, to_insert[i - 1]);
		new_vec.insert(new_vec.begin() + (index * n), vec.begin() + range, vec.begin() + range + n);

		i--;
	}



	int rem = static_cast<int>(vec.size()) % n;
	if (rem != 0)
		new_vec.insert(new_vec.end(), vec.begin() + static_cast<int>(vec.size()) - rem, vec.end());

	return (new_vec);
}

std::deque<int> PMergeMe::fj_deque(std::deque<int> deq, int n)
{
	//Step1 : Division into pairs and sorting

	if ((n * 2) > static_cast<int>(deq.size()))
		return deq;
	
	int nb_comp = static_cast<int>(deq.size()) / (n * 2);
	int idx1 = n - 1;
	int idx2 = idx1 + n;

	for (int i = 0; i < nb_comp; i++)
	{
		if (deq[idx2] < deq[idx1])
		{
			std::deque<int>::iterator range1 = deq.begin() + (2 * n * i);
			std::deque<int>::iterator range2 = range1 + n;
			std::swap_ranges(range1, range2, range2);
		}

		idx2 += (2 * n);
		idx1 += (2 * n);
	}
	deq = fj_deque(deq, n * 2);

	//Step2 : binary insertion algo

	// Init to_insert
	std::deque<int> to_insert;

	for (int i = n - 1; i < static_cast<int>(deq.size()); i += (2 * n)) {
		to_insert.push_back(deq[i]);
	}

	// Init search
	std::deque<int> search;
	search.push_back(deq[n - 1]);
	for (int i = (n * 2) - 1; i < static_cast<int>(deq.size()); i += (2 * n)) {
		search.push_back(deq[i]);
	}

	//Init new_deq that will be my new deque
	std::deque<int> new_deq;
	new_deq.insert(new_deq.end(), deq.begin(), deq.begin() + (n * 2));
	for (int i = (n * 3); (i + n - 1) < static_cast<int>(deq.size()); i += (2 * n)) {
		std::copy (deq.begin() + i, deq.begin() + i + n, std::back_inserter(new_deq));
	}

	//Binary insertion
	int k = 2;

	while (jacobsthal_number(k) <= static_cast<int>(to_insert.size()))
	{
		int i = jacobsthal_number(k);
		while (i > jacobsthal_number(k-1))
		{
			std::deque<int>::iterator it = std::lower_bound(search.begin(), search.begin() + (pow(2, k) - 1), to_insert[i - 1]);
			int index = it - search.begin();
			int range = 2 * (i - 1) * n;

			search.insert(search.begin() + index, to_insert[i - 1]);
			new_deq.insert(new_deq.begin() + (index * n), deq.begin() + range, deq.begin() + range + n);

			i--;
		}
		k++;
	}


	int i = to_insert.size();
	while (i > jacobsthal_number(k-1))
	{
		std::deque<int>::iterator it = std::lower_bound(search.begin(), search.end(), to_insert[i - 1]);
		int index = it - search.begin();
		int range = 2 * (i - 1) * n;
		search.insert(search.begin() + index, to_insert[i - 1]);
		new_deq.insert(new_deq.begin() + (index * n), deq.begin() + range, deq.begin() + range + n);

		i--;
	}



	int rem = static_cast<int>(deq.size()) % n;
	if (rem != 0)
		new_deq.insert(new_deq.end(), deq.begin() + static_cast<int>(deq.size()) - rem, deq.end());

	return (new_deq);
}

int PMergeMe::jacobsthal_number(int k) 
{
	return ((pow(2, k + 1) + pow(-1, k)) / 3);
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

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << vectortime << " ms\n";
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << dequetime << " ms\n";
}
