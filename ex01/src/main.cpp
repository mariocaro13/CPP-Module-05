/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:59 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/23 19:04:55 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	
	try
	{
		Bureaucrat a("Alice", 42);
		Bureaucrat b("Bob", 140);

		Form taxForm("Tax Form", 100, 50);
		Form secretForm("Secret Form", 20, 10);

		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		std::cout << "\nTrying to sign Tax Form:" << std::endl;
		a.signForm(taxForm);
		b.signForm(taxForm);

		std::cout << "\nTrying to sign Secret Form:" << std::endl;
		a.signForm(secretForm);
		b.signForm(secretForm);

		std::cout << "\nFinal Form Status:" << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}
	return (0);
}
