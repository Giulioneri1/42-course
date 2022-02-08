/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:50:51 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 12:55:29 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:
        Form();
		Form(const std::string name, const int gts, const int gte);
		Form(const Form& form);
        ~Form();

		Form&	operator=(const Form& form);

		const std::string&	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExe() const;
		bool				getSigned() const;

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

		class AlreadySigned: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void				beSigned(const Bureaucrat& bur);
};

std::ostream& operator<<(std::ostream& os, const Form& form);



#endif