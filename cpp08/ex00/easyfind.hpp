/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:04:18 by thomas            #+#    #+#             */
/*   Updated: 2024/12/16 14:56:10 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <algorithm>

//Exception
class NotFound: public std::exception
{
	const char* what() const throw() {
		return "Value not found!";
	}
};

template <typename T>
int* easyfind(T& container, int i)
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw NotFound();
	return &(*it);
}

#endif