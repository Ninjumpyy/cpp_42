/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:20:51 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//OCF
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) {(void)other;}
Serializer& Serializer::operator=(const Serializer& other) 
{
	(void)other;
	return (*this);
}
Serializer::~Serializer() {}

//Methods
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
