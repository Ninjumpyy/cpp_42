/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:22:13 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 17:30:03 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif