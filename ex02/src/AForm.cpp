/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:19:38 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/25 13:51:10 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm(void) {}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return (os);
}
