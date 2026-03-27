/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:59 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/27 16:38:14 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
	
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Mid", 50);
		Bureaucrat low("Low", 150);

		std::cout << "\n--- Creating Forms ---\n" << std::endl;

		ShrubberyCreationForm shrubbery("Home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "\n--- Trying to execute without signing ---\n" << std::endl;

		try 
		{
			shrubbery.execute(mid);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Execution error: " << e.what() << std::endl;
		}

		std::cout << "\n--- Signing Forms ---\n" << std::endl;

		boss.signForm(shrubbery);
		boss.signForm(robotomy);
		boss.signForm(pardon);

		std::cout << "\n--- Executing Forms ---\n" << std::endl;
		boss.executeForm(shrubbery);
		boss.executeForm(robotomy);
		boss.executeForm(pardon);

		std::cout << "\n--- Trying to execute with low bureaucracy ---\n" << std::endl;
		try
		{
			low.executeForm(pardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Execution error: " << e.what() << '\n';
		}
		
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	return (0);
}
