/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:10:38 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 13:19:58 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>

class RPN
{
	public:
		//Constructors
		RPN();
		RPN(const RPN& other);

		//Copy Assignment Operator
		RPN& operator=(const RPN& other);

		//Destructor
		~RPN();

		//Method
		int print_result_rpn(std::string input);

	private:
		std::stack<double> stack;

		//Helpers
		bool read_input(std::string input);
		double do_operation(char op, int nb1, int nb2);
		bool is_operator(char c);


};

#endif