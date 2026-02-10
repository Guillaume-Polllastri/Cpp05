/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:56:30 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/11 00:22:38 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): _name(name), _grade(grade) {
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::~Bureaucrat() {}

const std::string   Bureaucrat::getName() const {
    return (_name);
}

unsigned int    Bureaucrat::getGrade() const {
    return (_grade);
}

void    Bureaucrat::increment_grade() {
    _grade--;
	if (_grade < 1)
		throw (GradeTooHighException());
}

void    Bureaucrat::decrement_grade() {
    _grade++;
	if (_grade > 150)
		throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
