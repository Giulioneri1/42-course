/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:48:22 by gneri             #+#    #+#             */
/*   Updated: 2021/12/13 11:53:43 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

typedef struct s_data
{
    
} Data;

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif