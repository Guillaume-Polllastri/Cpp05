/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:59:52 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/12 14:37:20 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{

	try
	{
		Bureaucrat	toto("toto", 1);
		Bureaucrat	tata("tata", 150);
		Form		form("Construct form", 40, 20);

		std::cout << form << std::endl;
		// form.beSigned(toto);
		toto.signForm(form);
		tata.signForm(form);
		
		std::cout << "Before decrement: " << toto << " -----> ";
		toto.decrement_grade();
		std::cout << "After decrement: " << toto << std::endl;
		std::cout << "Before decrement: " << tata << " -----> ";
		tata.increment_grade();
		std::cout << "After decrement: " << tata << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}