/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:46 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 10:37:57 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string const _target;
	
	public:
		//Constructor
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);

		//Copy Constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);

		//Copy Assignment Operator deleted
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		//Destructor
		~PresidentialPardonForm();

		//Methods
		void execute(Bureaucrat const & executor) const;
};

#endif