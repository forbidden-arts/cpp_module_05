/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 07:37:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/26 07:51:15 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout <<std::endl << "Testing" << std::endl;
		std::cout << a;
		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << "" << std::endl;
		}
		std::cout << a;
		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << "" << std::endl;
		}
		std::cout << a;
		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << "" << std::endl;
		}
		std::cout << a;

		std::cout << std::endl << "Deconstructing" << std::endl;
		delete a;
	}
	
	std::cout << std::endl << "------" << std::endl;
	{
		std::cout << std::endl << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl << "Testing" << std::endl;
		std::cout << a;
		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << "" << std::endl;
		}
		std::cout << a;
		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << "" << std::endl;
		}
		std::cout << a;
		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << "" << std::endl;
		}
		std::cout << a;
		std::cout << std::endl << "Deconstructing" << std::endl;
		delete a;
	}

	std::cout << std::endl << "------" << std::endl;
	{
		std::cout << std::endl << "Constructing" << std::endl;
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Constructing default failed: " <<
			e.what() << "" << std::endl;
		}
		if (a != NULL)
		{
			std::cout << std::endl << "Deconstructing b" << std::endl;
			delete a;
		}
	}

	std::cout << std::endl << "------" << std::endl;
	{
		std::cout << std::endl << "Constructing" << std::endl;
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat(160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Constructing default failed: " <<
			e.what() << "" << std::endl;
		}
		if (a != NULL)
		{
			std::cout  << std::endl << "Deconstructing b" << std::endl;
			delete a;
		}
	}

	std::cout << std::endl << "------" << std::endl;
	{
		std::cout << std::endl << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Hermes", 120);
		std::cout << std::endl << "Testing a" << std::endl;
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		std::cout << std::endl << "Constructing b" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout  << std::endl << "Deconstructing a" << std::endl;
		delete a;
		std::cout << std::endl << "Testing b" << std::endl;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout  << std::endl << "Deconstructing b" << std::endl;
		delete b;
	}
}