/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:59:52 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 13:30:59 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{

	try
	{
		Bureaucrat	toto("toto", 1);
		Bureaucrat	tata("tata", 150);


		Intern	intern;
		AForm*	shru;
		AForm*	robo;
		AForm*	pres;

		shru = intern.makeForm("shrubbery creation", "test");
		robo = intern.makeForm("robotomy request", "bender");
		pres = intern.makeForm("presidential pardon", "tlorette");
		
		toto.signForm(*shru);
		toto.signForm(*robo);
		toto.signForm(*pres);
		
		shru->execute(toto);
		robo->execute(toto);
		pres->execute(toto);

		delete (shru);
		delete (robo);
		delete (pres);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}