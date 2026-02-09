/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:56:30 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/09 16:56:33 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat() {}

const std::string   Bureaucrat::getName() {
    return (_name);
}

unsigned int    Bureaucrat::getGrade() {
    return (_grade);
}

void    Bureaucrat::increment_grade() {
    if (_grade > 0 && _grade < 150)
        _grade++;        
}

void    Bureaucrat::decrement_grade() {
    if (_grade > 1 && _grade <= 150)
        _grade--;
}
