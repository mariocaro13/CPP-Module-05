/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:58:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/25 16:14:34 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}	

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->checkExecution(executor);

	std::string filename = this->_target + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs)
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\\\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "      // \\\\" << std::endl;

	ofs.close();
}
