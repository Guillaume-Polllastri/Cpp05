/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:56:33 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/09 16:48:43 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat
{
    private:
    const std::string   _name;
    unsigned int        _grade;
    
    public:
    Bureaucrat(const std::string& name, unsigned int grade);
    ~Bureaucrat();

    const std::string   getName();
    unsigned int        getGrade();
    void                increment_grade();
    void                decrement_grade();
};