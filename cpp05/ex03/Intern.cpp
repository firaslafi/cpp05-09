/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:05 by flafi             #+#    #+#             */
/*   Updated: 2024/04/24 15:41:08 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Intern.hpp"

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

Form* Intern::makeForm(string &name, string target)
{
    
}