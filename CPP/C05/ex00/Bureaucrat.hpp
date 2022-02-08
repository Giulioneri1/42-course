/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:46:22 by gneri             #+#    #+#             */
/*   Updated: 2021/11/29 17:34:47 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
    private:
		const std::string	_name;
		int		_grade;		
    public:
        Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
        ~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);

		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string&		getName() const;
		int 			getGrade() const;
		void					incrGrade();
		void					decrGrade();

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);


#endif