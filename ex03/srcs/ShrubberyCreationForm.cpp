/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:33:33 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 12:54:07 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): 
	AForm("ShrubberyCreationForm", 145, 137),
 	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
	AForm(copy),
	_target(copy._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	requirement(executor);
	std::ofstream	file((this->_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "              * *    \n";
		file << "          *    *  *\n";
		file << "     *  *    *     *  *\n";
		file << "    *     *    *  *    *\n";
		file << "* *   *    *    *    *   *\n";
		file << "*     *  *    * * .#  *   *\n";
		file << "*   *     * #.  .# *   *\n";
		file << " *     \"#.  #: #\" * *    *\n";
		file << "*   * * \"#. ##\"       *\n";
		file << "  *       \"###\n";
		file << "            \"##\n";
		file << "             ##.\n";
		file << "             .##:\n";
		file << "             :###\n";
		file << "             ;###\n";
		file << "           ,####.\n";
		file << "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n";
		file.close();
	}
}
