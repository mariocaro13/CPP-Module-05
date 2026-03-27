/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:59 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/27 17:05:38 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void testValidForms(Intern &intern, AForm *&shrubbery, AForm *&robotomy, AForm *&pardon)
{
	std::cout << "\n--- Testing valid form creation ---\n" << std::endl;
	try
	{
		shrubbery = intern.makeForm("shrubbery creation", "Home");
		robotomy = intern.makeForm("robotomy request", "Bender");
		pardon = intern.makeForm("presidential pardon", "Arthur Dent");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error creating form: " << e.what() << std::endl;
	}
}

void testSigning(Bureaucrat &boss, AForm *shrubbery, AForm *robotomy, AForm *pardon)
{
	std::cout << "\n--- Signing Forms ---\n" << std::endl;
	if (shrubbery) boss.signForm(*shrubbery);
	if (robotomy) boss.signForm(*robotomy);
	if (pardon) boss.signForm(*pardon);
}

void testExecution(Bureaucrat &boss, AForm *shrubbery, AForm *robotomy, AForm *pardon)
{
	std::cout << "\n--- Executing Forms ---\n" << std::endl;
	if (shrubbery) boss.executeForm(*shrubbery);
	if (robotomy) boss.executeForm(*robotomy);
	if (pardon) boss.executeForm(*pardon);
}

void testInvalidForm(Intern &intern)
{
	std::cout << "\n--- Testing invalid form creation ---\n" << std::endl;
	try
	{
		AForm *invalid = intern.makeForm("invalid form", "Target");
		delete invalid;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Expected error for invalid form: " << e.what() << std::endl;
	}
}

int main(void)
{
	try
	{
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1);

		AForm *shrubbery = NULL;
		AForm *robotomy = NULL;
		AForm *pardon = NULL;

		testValidForms(someRandomIntern, shrubbery, robotomy, pardon);

		testSigning(boss, shrubbery, robotomy, pardon);
		testExecution(boss, shrubbery, robotomy, pardon);
		
		testInvalidForm(someRandomIntern);

		delete shrubbery;
		delete robotomy;
		delete pardon;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	return (0);
}
