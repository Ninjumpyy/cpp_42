/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:03:41 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/19 14:50:54 by tle-moel         ###   ########.fr       */
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

		//Comparison operators
			bool &operator>(const Fixed &other);
			bool &operator<(const Fixed &other);
			bool &operator>=(const Fixed &other);
			bool &operator<=(const Fixed &other);
			bool &operator==(const Fixed &other);
			bool &operator!=(const Fixed &other);
		
		//Arithmetic operators
			Fixed &operator+(const Fixed &other);
			Fixed &operator-(const Fixed &other);
			Fixed &operator*(const Fixed &other);
			Fixed &operator/(const Fixed &other);
		
		//Decrement and Increment operators
			Fixed &operator++();
			Fixed &operator++(int);
			Fixed &operator--();
			Fixed &operator--(int);
            
        //Member functions
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min(Fixed obj1, Fixed obj2);
		static Fixed &min(const Fixed obj1, const Fixed obj2);
		static Fixed &max(Fixed obj1, Fixed obj2);
		static Fixed &max(const Fixed obj1, const Fixed obj2);

		// Friend function for << operator
			friend std::ostream& operator<<(std::ostream &os, const Fixed &other);
};

#endif