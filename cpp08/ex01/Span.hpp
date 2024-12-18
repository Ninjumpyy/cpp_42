/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:59 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 16:30:51 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <algorithm>
# include <climits>

class Span
{
	private:
		std::vector<int> _container;
		
	public:
		//Constructors
		Span();
		Span(unsigned int N);
		Span(const Span& other);

		//Copy Assignment Operator
		Span& operator=(const Span& other);

		//Destructor
		~Span();

		//Member functions
		void	addNumber(int nb);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

		//Exceptions
		class TooManyElements: public std::exception
		{
			const char *what() const throw();
		};

		class TooFewElements: public std::exception
		{
			const char *what() const throw();
		};
};

#endif