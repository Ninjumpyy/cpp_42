/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:06 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 12:12:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

//Constructor
AForm::AForm(): _name("Default"), _signed(false), _grade_to_sign(1), _grade_to_execute(1) {}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute): _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException();
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException();
}

//Copy Constructor
AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {}

//Copy Assignment Operator deleted here because const attributes
AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	return (*this);
}

//Destructor
AForm::~AForm() {}

//Member functions
std::string const& AForm::getName() const
{
	return (_name);	
}

bool	AForm::getSignedStatus() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_grade_to_sign);
}

int	AForm::getGradeToExecute() const
{
	return (_grade_to_execute);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::canExecute(const Bureaucrat& b) const
{
	if (!getSignedStatus())
		throw NotSigned();
	if (b.getGrade() > _grade_to_execute)
		throw GradeTooLowException();
}

//Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::NotSigned::what() const throw()
{
	return "Form is not signed!";
}

//Overload for insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "Name: " << other.getName() << ", is signed: ";
	if (other.getSignedStatus())
		os << "Yes";
	else
		os << "No";
	os << ", grade to sign : " << other.getGradeToSign() << ", grade to execute : " << other.getGradeToExecute();
	return (os);
}
