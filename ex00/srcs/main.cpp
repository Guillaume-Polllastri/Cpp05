/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:59:52 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/11 00:26:07 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{

	try
	{
		Bureaucrat	toto("toto", 1);
		Bureaucrat	tata("tata", 150);

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