/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:50:51 by gneri             #+#    #+#             */
/*   Updated: 2021/12/01 15:59:21 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:
        AForm();
		AForm(const std::string name, const int gts, const int gte);
		AForm(const AForm& Aform);
        virtual ~AForm();

		AForm&	operator=(const AForm& Aform);

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

		class FormNotSigned: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void						beSigned(const Bureaucrat& bur);
		void						execute(const Bureaucrat& executor) const;
		virtual void				FormAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);



#endif