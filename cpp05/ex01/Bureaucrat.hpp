/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:44:37 by thomas            #+#    #+#             */
/*   Updated: 2024/12/03 18:10:42 by tle-moel         ###   ########.fr       */
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
	protected:
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