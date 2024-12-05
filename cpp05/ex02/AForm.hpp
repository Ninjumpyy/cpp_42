/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:09 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 12:10:57 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool	_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;

	public:
		//Constructor
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_execute);

		//Copy Constructor
		AForm(const AForm& other);

		//Copy Assignment Operator deleted here because const attributes
		AForm& operator=(const AForm& other);

		//Destructor
		virtual ~AForm();

		//Member functions
		std::string const& getName() const;
		bool getSignedStatus() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);
		void canExecute(const Bureaucrat& b) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

		//Exceptions
		class GradeTooHighException: public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char *what() const throw();
		};

		class NotSigned: public std::exception
		{
			const char *what() const throw();
		};
};

//Overload for insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif