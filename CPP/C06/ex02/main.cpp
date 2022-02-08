/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:42:07 by gneri             #+#    #+#             */
/*   Updated: 2021/12/10 12:27:43 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void    identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;   
}

Base    *generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;

    if (i == 0)
        return (new A);
    if (i == 1)
        return (new B);
    if (i == 2)
        return (new C);
    return NULL;
}

int main()
{
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
}