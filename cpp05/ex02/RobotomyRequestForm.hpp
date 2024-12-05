/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:54 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 11:28:09 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		std::string const _target;
	
	public:
		//Constructor
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);

		//Copy Constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);

		//Copy Assignment Operator deleted
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		//Destructor
		~RobotomyRequestForm();

		//Methods
		void execute(Bureaucrat const & executor) const;
};

#endif