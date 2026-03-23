/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:47:59 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/23 18:18:54 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n------------- Normal Creation ----------------" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;
		a.decrementGrade();
		std::cout << "After decrement: " << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n------------- Grade too high ----------------" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n------------- Grade too low ----------------" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n------------- Increment beyond limit ----------------" << std::endl;
	try
	{
		Bureaucrat d("David", 1);
		std::cout << d << std::endl;
		d.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n------------- Decrement beyond limit ----------------" << std::endl;
	try
	{
		Bureaucrat d("David", 150);
		std::cout << d << std::endl;
		d.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
