/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:10:31 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 13:34:54 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Constructors
RPN::RPN(): stack() {}
RPN::RPN(const RPN& other): stack(other.stack) {}

//Copy Assignment Operator
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return (*this);
}

//Destructor
RPN::~RPN() {}

//Method

int RPN::print_result_rpn(std::string input)
{
	if (!RPN::read_input(input))
		return 0; //Indicate failure...
	return 1;
}

//Helpers
bool RPN::read_input(std::string input)
{	
	for (std::size_t i = 0; i < input.size(); i++)
	{
		if (std::isdigit(input[i])) {
			stack.push(static_cast<double>(input[i] - 48));
			if (i + 1 < input.size() && input[i + 1] != ' ')
				return false;
		}
		else if (RPN::is_operator(input[i])) {
			if (stack.size() < 2)
				return false;
			int nb1 = stack.top();
			stack.pop();
			int nb2 = stack.top();
			stack.pop();
			stack.push(RPN::do_operation(input[i], nb1, nb2));
		}
		else if (input[i] != ' ') {
			std::cout << "Error\n";
			return false;
		}
	}
	if (stack.size() != 1)
		return false;
	std::cout << stack.top() << std::endl;	
	return true;
}

double RPN::do_operation(char op, int nb1, int nb2)
{
	if (op == '+')
		return (nb2 + nb1);
	else if (op == '-')
		return (nb2 - nb1);
	else if (op == '*')
		return (nb2 * nb1);
	else
		return (nb2 / nb1);
}

bool RPN::is_operator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}