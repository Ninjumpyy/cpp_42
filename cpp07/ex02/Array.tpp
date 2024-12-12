/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:18:58 by thomas            #+#    #+#             */
/*   Updated: 2024/12/12 15:43:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//Constructors
template <typename T>
Array<T>::Array(): _size(0)
{
	array = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	_size = other.size();
	array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		array[i] = other.array[i];
	}
}

//Copy Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		_size = other.size();
		delete[] array;
		array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			array[i] = other.array[i];
		}
	}
	return (*this);
}

//Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

//Overloading of []
template <typename T>
T& Array<T>::operator[](unsigned int n) const
{
	if (n >= size())
		throw std::exception();
	return array[n];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
