/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:15:56 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 11:14:23 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mutantstack.hpp"

int main()
{
    Mutantstack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top number is: "<< mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Top number removed" << std::endl;
    std::cout << "Top number is: "<< mstack.top() << std::endl;
    std::cout <<"Size is: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    Mutantstack<int>::iterator it = mstack.begin();
    Mutantstack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}