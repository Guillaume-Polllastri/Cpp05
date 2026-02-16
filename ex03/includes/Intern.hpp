/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:18:33 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 00:55:33 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& name, const std::string& target);

	class BadFormNameException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "The provided form name does not exist !";
			}
	};
};