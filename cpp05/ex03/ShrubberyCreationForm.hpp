/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:31:00 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 11:06:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

// Helper macros for colors
# define RESET   "\033[0m"   // Reset to default
# define RED		"\033[31m"	// Red
# define GREEN   "\033[32m"  // Green
# define YELLOW  "\033[33m"  // Yellow
# define BLUE    "\033[34m"  // Blue
# define MAGENTA "\033[35m"  // Magenta
# define CYAN    "\033[36m"  // Cyan

class ShrubberyCreationForm: public AForm
{
	private:
		std::string const _target;
	
	public:
		//Constructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);

		//Copy Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);

		//Copy Assignment Operator deleted
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		//Destructor
		~ShrubberyCreationForm();

		//Methods
		void execute(Bureaucrat const & executor) const;
};

#endif