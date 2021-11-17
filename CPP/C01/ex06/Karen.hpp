/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:19:23 by gneri             #+#    #+#             */
/*   Updated: 2021/11/12 15:23:15 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
private:
	void	debug();
	void	info();
	void	warning();
	void	error();
public:
	Karen();
	~Karen();
	void	complain(std::string level);
};

typedef	void	(Karen::*ptrToFun)();
#endif