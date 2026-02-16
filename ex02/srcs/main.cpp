/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:59:52 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 21:37:59 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

	try
	{
		Bureaucrat	toto("toto", 1);
		Bureaucrat	tata("tata", 150);

		ShrubberyCreationForm	shru("test");
		RobotomyRequestForm		robo("bender");
		PresidentialPardonForm	pres("tlorette");

		toto.signForm(shru);
		toto.signForm(robo);
		toto.signForm(pres);

		toto.executeForm(shru);
		toto.executeForm(robo);
		toto.executeForm(pres);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}