/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:22:36 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 12:05:01 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdbool.h>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private:
    const std::string   _name;
    bool                _isSigned;
    const unsigned int  _gradeToSign;
    const unsigned int  _gradeToExecute;
    
	protected:
	void			requirement(Bureaucrat const & executor) const;

    public:
    AForm(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
    AForm(const AForm& copy);
    AForm&   operator=(const AForm& other);
    virtual ~AForm();

    std::string     getName() const;
    bool            getIsSigned() const;
    unsigned int    getGradeToSign() const;
    unsigned int    getGradeToExecute() const;
    
    void    		beSigned(const Bureaucrat& bureaucrat);
    virtual void    execute(Bureaucrat const & executor) = 0;
    
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
	
	class FormIsNotSignedException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Form is not signed !";
			}
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);
