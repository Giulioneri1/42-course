/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:51:05 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 12:30:14 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

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

	void						signForm(Form& form) const;
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);


#endif