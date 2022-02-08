/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:34:28 by gneri             #+#    #+#             */
/*   Updated: 2021/11/25 14:30:37 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& brain);
        ~Brain();

        Brain&              operator=(const Brain& brain);
        void                setIdeas(const std::string& idea);
        const std::string*  getIdeas() const;
        void                printIdeas() const;
};


#endif