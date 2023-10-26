/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:50:13 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/26 08:55:16 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class From;

class RobotomyRequestForm: public Form
{
	private:
		const std::string _target;
		RobotomyRequestForm();
		
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif