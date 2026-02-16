/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:18:42 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 01:05:50 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	(void) copy;
}

Intern&	Intern::operator=(const Intern& other) {
	(void) other;
	return *this;
}

Intern::~Intern() {}

static	AForm*	createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm*	createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm*	createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::string	formNames[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm*	(*forms[3])(const std::string& target) =
	{
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
			return (forms[i](target));
	}
	throw Intern::BadFormNameException();
}
