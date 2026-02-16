/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:38:47 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 13:51:41 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

// CANONICAL FORM

AForm::AForm(const std::string& name, const unsigned int gradeToSign, const unsigned int gradeToExecute):
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) 
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& copy):
    _name(copy._name),
	_isSigned(copy._isSigned),
    _gradeToSign(copy._gradeToSign),
    _gradeToExecute(copy._gradeToExecute)
{
}

AForm&   AForm::operator=(const AForm& other) {
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

AForm::~AForm() {}


// GETTERS

std::string   AForm::getName() const {
    return this->_name;
}

bool	AForm::getIsSigned() const {
	return this->_isSigned;
}

unsigned int	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

unsigned int	AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// OVERLOAD OPERATOR <<

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << '[' << form.getName() << ']' << " Grade to sign: " << form.getGradeToSign()
	<< " | Grade to execute: " << form.getGradeToExecute();
	return (os);
}

// METHODS

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::requirement(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}
