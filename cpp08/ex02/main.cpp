/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:07:04 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:01:52 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void basic_test()
{
	std::cout << "--- Basic Test ---\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void test_with_list() {
    std::cout << "\n--- Testing with std::list ---" << std::endl;

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl; // Equivalent to top() for std::list
    mlist.pop_back();
    std::cout << mlist.size() << std::endl; // Should print 1
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

void const_iterator_test()
{
    std::cout << "\n--- Const Iterator Test ---\n";
    MutantStack<int> mstack;
    mstack.push(42);
    mstack.push(84);
    mstack.push(126);

    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Ensures const_iterator does not allow modification
    // *it = 999; // Uncommenting this line should cause a compilation error
}

void reverse_iterator_test()
{
    std::cout << "\n--- Reverse Iterator Test ---\n";
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
}

void const_reverse_iterator_test()
{
    std::cout << "\n--- Const Reverse Iterator Test ---\n";
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);

    MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // Ensures const_reverse_iterator does not allow modification
    // *rit = 999; // Uncommenting this line should cause a compilation error
}

int main()
{
    basic_test();
	test_with_list();
    const_iterator_test();
    reverse_iterator_test();
    const_reverse_iterator_test();

    return 0;
}
