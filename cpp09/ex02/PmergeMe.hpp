/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:11:48 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 15:44:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

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
		// ...

	private:
	
};

#endif