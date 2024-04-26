/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:14 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 15:40:57 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5)
{
    this->_target = "defaultTarget";   
}
PresidentialPardonForm::PresidentialPardonForm(string target): Form("PresidentialPardonForm", 25, 5), _target(target)
{
    // this->_target = "defaultTarget";   
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{}
// copy assign and copy operator
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source): Form(source)
{
    *this = source;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
    this->_target = source._target;
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == false)
        throw Form::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << endl;
}

std::ostream &operator<<(std::ostream &outpudstream, PresidentialPardonForm const &obj)
{
    outpudstream << "PresidentialPardonForm under the name of " << obj.getName() << endl;
    return (outpudstream);
}