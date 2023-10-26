/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:16:23 by dpalmer           #+#    #+#             */
/*   Updated: 2023/10/26 11:04:10 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;
		Form();
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);

	public:
		Form(const Form &src);
		Form &operator=(const Form &src);
		virtual ~Form();

		void beSigned(Bureaucrat &signer);
		virtual void execute(Bureaucrat const &executor)const = 0;

		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Form *a);

#endif
