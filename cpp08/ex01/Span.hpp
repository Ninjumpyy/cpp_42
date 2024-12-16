/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:59 by thomas            #+#    #+#             */
/*   Updated: 2024/12/16 17:02:40 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
	private:
		std::vector<int> V;
		
	public:
		//Constructors
		Span();
		Span(unsigned int n);
		Span(const Span& other);

		//Copy Assignment Operator
		Span& operator=(const Span& other);

		//Destructor
		~Span();

		//Member functions
		void	addNumber(int nb);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void	addRandomNumbers(unsigned int size);

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