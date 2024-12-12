/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:09:20 by thomas            #+#    #+#             */
/*   Updated: 2024/12/12 15:32:07 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
	private:
		T* array;
		unsigned int _size;

	public:
		//Constructors
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		
		//Copy assignment operator
		Array& operator=(const Array& other);

		//Destructor
		~Array();

		//[] overloading
		T& operator[](unsigned int n) const;

		//Member function
		unsigned int size() const;
};

# include "Array.tpp"

#endif