/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:05 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 16:06:14 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Intern.hpp"
#include "RobotomyRequestForm.hpp"
 #include "ShrubberyCreationForm.hpp"
  #include "PresidentialPardonForm.hpp"

Intern::Intern()
{}
Intern::~Intern()
{}
Intern::Intern(Intern const &source)
{
    *this = source;
}
Intern& Intern::operator=(const Intern &source)
{
    return (*this);
}

Form* Intern::makeForm(string name, string target)
{
    string FormType[3] = 
    {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    
    Form* forms[3] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)};
    int i = 0;
    Form* result = nullptr;
    while(i < 3)
    {
        if (name == FormType[i])
        {
            cout << "Intern creates " << name << endl;
            result = forms[i];
            break;
        }
        i++;
    }
    if (result == nullptr)
        cout << "Intern Cannot creates " << name << endl;
    return (result);
}
