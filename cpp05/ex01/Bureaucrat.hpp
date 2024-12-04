/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:44:37 by thomas            #+#    #+#             */
/*   Updated: 2024/12/04 10:17:33 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int	_grade;
		
	public:
		//Constructor
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);

		//Copy Constructor
		Bureaucrat(const Bureaucrat& other);

		//Copy Assignment Operator
		Bureaucrat& operator=(const Bureaucrat& other);

		//Destructor
		~Bureaucrat();

		//Member functions
		std::string const& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(Form& f);

		//Exceptions
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();	
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

//Overload of operator
std::ostream& operator<<(std::ostream &os, const Bureaucrat& other);

#endif