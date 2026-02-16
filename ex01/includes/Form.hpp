/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:22:36 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 13:40:41 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdbool.h>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private:
    const std::string   _name;
    bool                _isSigned;
    const unsigned int  _gradeToSign;
    const unsigned int  _gradeToExecute;
    
    public:
    Form(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
    Form(const Form& copy);
    Form&   operator=(const Form& other);
    ~Form();

    std::string   	getName() const;
    bool			getIsSigned() const;
    unsigned int  	getGradeToSign() const;
    unsigned int  	getGradeToExecute() const;
    
    void    beSigned(const Bureaucrat& bureaucrat);
    
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Grade is too HIGH !";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Grade is too LOW !";
			}
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);
