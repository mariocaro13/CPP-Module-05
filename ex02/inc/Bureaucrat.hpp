/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:15:20 by mcaro-ro          #+#    #+#             */
/*   Updated: 2026/03/25 16:07:49 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string& getName(void) const;
		int getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void signForm(AForm &form);
		void executeForm(const AForm &form);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
