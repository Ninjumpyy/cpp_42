/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:44:37 by thomas            #+#    #+#             */
/*   Updated: 2024/12/02 12:55:03 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	private:
		std::string const _name;
		int	_grade;
	public:
		//Constructor
		Bureaucrat();
		Bureaucrat(std::string const &name, int& grade);

		//Copy Constructor
		Bureaucrat(const Bureaucrat& other);

		//Copy Assignment Operator
		Bureaucrat& operator=(const Bureaucrat& other);

		//Destructor
		~Bureaucrat();

		//Getters
		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		

};

#endif