/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:56:33 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/16 21:34:56 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
    private:
    const std::string   _name;
    unsigned int        _grade;
    
    public:
    Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string   getName() const;
    unsigned int        getGrade() const;
    void                increment_grade();
    void                decrement_grade();

	void	signForm(AForm& form);
	void	executeForm(AForm const& form) const;
	
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Grade is too high !";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Grade is too low !";
			}
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
