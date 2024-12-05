/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:20:26 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 14:09:00 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		//Constructor
		Intern();

		//Copy Constructor
		Intern(const Intern& other);

		//Copy Assignment Operator
		Intern& operator=(const Intern& other);

		//Destructor
		~Intern();

		//Method
		AForm*	makeForm(std::string form_name, std::string target) const;

		//Exception
		class	NotFind: public std::exception
		{
			const char *what() const throw();
		};
};

#endif