/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:20:01 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 15:47:47 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include "stdint.h"

class Serializer
{
	private:
		// Private constructors to prevent instantiation
		Serializer();
		Serializer(const Serializer& other);

		// Delete copy assignment operator
		Serializer& operator=(const Serializer& other);
		~Serializer();
	
	public:
		//Methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif