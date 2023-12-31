/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:33:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/26 11:57:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new PresidentialPardonForm("default");
		// Form *c = new RobotomyRequestForm();
		// Form *d = new ShrubberyCreationForm();

		std::cout << "\nTesting" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << "\nDeconstructing" << std::endl;
		delete a;
		delete b;
	}
	std::cout << "\n------" << std::endl;
	{
		std::cout << "\nConstructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("some dude");

		std::cout << "\nTesting" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		// Assistant signs the Form
		try
		{
			c->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}

		// CEO signs the Form
		std::cout << c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
		}
		// catch(Form::GradeTooLowException &e)
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << c;
		std::cout << std::endl;

		// try signing the from again
		b->signForm(*c);
		std::cout << std::endl;

		// execute the Form from assistant
		try
		{
			c->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}

		// execute Form from CEO
		try
		{
			c->execute(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}

		std::cout << "\nDeconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
	}
	std::cout << "\n------" << std::endl;
	{

		std::cout << "\nConstructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Dan", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);

		std::cout << "\nTesting" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		b->execute(*a);
		a->executeForm(*c);

		std::cout << "\nDeconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
	}
	std::cout << "\n------" << std::endl;
	{

		std::cout << "\nConstructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Dan", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");

		std::cout << "\nTesting" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		c->execute(*a);

		std::cout << "\nDeconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
	}
	return (0);
}
