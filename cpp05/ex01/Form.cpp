/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:27:23 by tle-moel          #+#    #+#             */
/*   Updated: 2024/12/03 18:08:46 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

//Constructor
Form::Form(): _name("Default"), _signed(false), _grade_to_sign(1), _grade_to_execute(1) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute): _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException();
}

//Copy Constructor
Form::Form(const Form& other): _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {}

//Copy Assignment Operator
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
		_grade_to_sign = other._grade_to_sign;
		_grade_to_execute = other._grade_to_execute;
	}
	return (*this);
}

//Destructor
Form::~Form() {}

//Member functions
std::string const& Form::getName() const
{
	return (_name);	
}

bool	Form::getSignedStatus() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_grade_to_sign);
}

int	Form::getGradeToExecute() const
{
	return (_grade_to_execute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_signed = true;
}

//Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "Name: " << other.getName() << ", is signed: " << other.getSignedStatus() << ", grade to sign : " << other.getGradeToSign() << ", grade to execute : " << other.getGradeToExecute() << std::endl;
	return (os);
}