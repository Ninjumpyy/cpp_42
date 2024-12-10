/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:59:22 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 12:03:54 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_HPP
# define HELPER_HPP

# include <string>
# include <limits>
# include <cerrno>
# include <iostream>
# include <cstdlib>
# include <cmath>

bool	is_char(const std::string& s);
bool	is_int(const std::string& s);
bool	is_float(const std::string& s);
bool	is_double(const std::string& s);
void	display_from_char(const std::string& s);
void	display_from_int(const std::string& s);
void	display_from_float(const std::string& s);
void	display_from_double(const std::string& s);


#endif