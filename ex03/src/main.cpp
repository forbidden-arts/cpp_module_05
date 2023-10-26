/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:33:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/26 11:57:15 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "Constructing" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		Form *b = z->makeForm("SomeRandomForm", "Rasmus");
		b = z->makeForm("PresidentialPardonForm", "Rasmus");
		// Form *b = new PresidentialPardonForm("Clown");
		// Form *c = new RobotomyRequestForm("Bender");
		// Form *d = new ShrubberyCreationForm("Christmas");

		std::cout << "\nTesting" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << b;

		std::cout << "\nDeconstructing" << std::endl;
		delete a;
		delete b;
		delete z;
	}
	std::cout << "\n------" << std::endl;
	{
		std::cout << "\nConstructing" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("Rasmus");

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
		std::cout << std::endl;
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
		std::cout << std::endl;
		std::cout << c;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << c;

		// try signing the from again
		std::cout << std::endl;
		b->signForm(*c);

		// execute the Form from assistant
		try
		{
			c->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;

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
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		Intern *z = new Intern();
		Form *b = z->makeForm("RobotomyRequestForm", "Bender");
		Form *c = z->makeForm("ShrubberyCreationForm", "christmas");
		// Form *c = new ShrubberyCreationForm("christmas");

		std::cout << "\nTesting" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signForm(*c);
		std::cout << std::endl;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);

		std::cout << "\nDeconstructing" << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	}
	return (0);
}
