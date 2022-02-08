/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:34:32 by gneri             #+#    #+#             */
/*   Updated: 2021/11/25 14:30:46 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "A brain has been created" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "FULLOA";
}

Brain::~Brain()
{
    std::cout << "A brain has died" << std::endl;
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
}

Brain&	Brain::operator=(const Brain& brain)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    return *this;
}

void    Brain::setIdeas(const std::string& idea)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

const std::string*   Brain::getIdeas() const
{
    return this->ideas;
}

void    Brain::printIdeas() const
{
    for (int i = 0; i < 5; i++)
        std::cout << this->ideas[i] << std::endl;
}