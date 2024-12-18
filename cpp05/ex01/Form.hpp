/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:15:58 by tle-moel          #+#    #+#             */
/*   Updated: 2024/12/04 10:18:20 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool	_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;

	public:
		//Constructor
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);

		//Copy Constructor
		Form(const Form& other);

		//Copy Assignment Operator deleted here because const attributes
		Form& operator=(const Form& other);

		//Destructor
		~Form();

		//Member functions
		std::string const& getName() const;
		bool getSignedStatus() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

		//Exceptions
		class GradeTooHighException: public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char *what() const throw();
		};
};

//Overload for insertion operator
std::ostream& operator<<(std::ostream& os, const Form& other);

#endif