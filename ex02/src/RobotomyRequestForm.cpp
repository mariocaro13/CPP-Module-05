/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:50:14 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/25 16:16:13 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecution(executor);

	std::cout << "* BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ *" << std::endl;

	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
}
