/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:03:03 by thomas            #+#    #+#             */
/*   Updated: 2024/11/18 17:53:51 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

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
        //Copy Assignment operator

        //Destructor
        
        //Member functions
        int     getRawBits(void);
        void    setRawBits(int const raw);
};