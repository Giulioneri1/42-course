/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:13:44 by gneri             #+#    #+#             */
/*   Updated: 2022/01/14 11:28:11 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data data;
    Data *tmp = &data;
    uintptr_t raw;

    std::cout << "Indirizzo di data: " << tmp << std::endl;
    raw = serialize(tmp);
    std::cout << "Indirizzo serializzato: " << raw << std::endl;
    tmp = deserialize(raw);
    std::cout << "Indirizzo di tmp dopo deserialize: " << tmp << std::endl;

    // std::cout << "Indirizzo di data: " << &data << std::endl;
    // tmp = deserialize(serialize(tmp));
    // std::cout << tmp << std::endl;
    
}