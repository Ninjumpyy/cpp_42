/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:07:11 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 17:39:46 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		//Constructors
		MutantStack(): std::stack<T>() {}
		MutantStack(const MutantStack& other): std::stack<T>(other) {}

		//Copy Assignment Operator
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return (*this);
		}

		//Destructor
		~MutantStack() {};

		//Iterator
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const
		{
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const
		{
			return this->c.rend();
		}
};

#endif