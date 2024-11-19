/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:39:44 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/19 13:44:09 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    
    public:
        //Constructor
            Fixed();
			Fixed(const int value);
			Fixed(const float value);
			
        //Copy Constructor
            Fixed(const Fixed &other);

        //Copy Assignment Operator
            Fixed &operator=(const Fixed &other);

        //Destructor
            ~Fixed();

		// Friend function for << operator
			friend std::ostream& operator<<(std::ostream &os, const Fixed &other);
            
        //Member functions
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif