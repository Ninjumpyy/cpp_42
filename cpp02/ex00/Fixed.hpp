/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:03:03 by thomas            #+#    #+#             */
/*   Updated: 2024/11/19 11:30:09 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
    
    public:
        //Constructor
            Fixed();

        //Copy Constructor
            Fixed(const Fixed &other);

        //Copy Assignment Operator
            Fixed &operator=(const Fixed &other);

        //Destructor
            ~Fixed();
            
        //Member functions
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif