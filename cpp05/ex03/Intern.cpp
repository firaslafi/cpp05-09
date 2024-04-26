/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:05 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 16:28:26 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(Intern const &source)
{
	*this = source;
}
Intern &Intern::operator=(const Intern &source)
{
	return (*this);
}

Form	*makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
Form	*makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}
Form	*makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(string name, string target)
{

	int		i;
	Form	*result;

	string FormType[3] = 
    {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    
    typedef Form *(*functionPtr)(string target);
	functionPtr forms[3] = { &makeRobotomyRequestForm, &makePresidentialPardonForm, &makeShrubberyCreationForm};
	i = 0;
	result = nullptr;
	while (i < 3)
	{
		if (name == FormType[i])
		{
			cout << "Intern creates " << name << endl;
			result = forms[i](target);
			break ;
		}
		i++;
	}
	if (result == nullptr)
		cout << "Intern Cannot creates " << name << endl;
	return (result);
}
