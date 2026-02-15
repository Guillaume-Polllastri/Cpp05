/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:38:47 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/15 19:33:23 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

// CANONICAL FORM

Form::Form(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute):
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) 
{}

Form::Form(const Form& copy):
    _name(copy._name),
	_isSigned(copy._isSigned),
    _gradeToSign(copy._gradeToSign),
    _gradeToExecute(copy._gradeToExecute)
{
}

Form&   Form::operator=(const Form& other) {
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

Form::~Form() {}


// GETTERS

std::string   Form::getName() const {
    return this->_name;
}

bool	Form::getIsSigned() const {
	return this->_isSigned;
}

unsigned int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

unsigned int	Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// OVERLOAD OPERATOR <<

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	os << '[' << form.getName() << ']' << " Grade to sign: " << form.getGradeToSign()
	<< " | Grade to execute: " << form.getGradeToExecute();
	return (os);
}

// METHODS

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}
