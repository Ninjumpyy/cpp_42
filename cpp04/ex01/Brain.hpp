/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:52:44 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 10:32:47 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		//Constructor
		Brain();

		//Copy Constructor
		Brain(const Brain& other);

		//Copy Assignment Operator
		Brain& operator=(const Brain& other);

		//Destructor
		~Brain();

		//Member functions
		std::string getIdea(const unsigned int index) const;
		void		setIdea(const unsigned int index, const std::string idea);
};

#endif