/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:20 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 15:40:44 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45)
{
    this->_target = "defaultTarget";   
}
RobotomyRequestForm::RobotomyRequestForm(string target): Form("RobotomyRequestForm", 72, 45), _target(target)
{
    // this->_target = "defaultTarget";   
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{}
// copy assign and copy operator
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source): Form(source)
{
    *this = source;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
    this->_target = source._target;
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == false)
        throw Form::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    cout << "Drrr Trrrr Vrrrr *drilling noises*" << endl;
    srand(time(0));
    if (rand() % 3 == 0)
        cout << this->_target << " has been robotomized!" << endl;
    else
        cout << "Robotomy failed! :(" << endl;
    
}

std::ostream &operator<<(std::ostream &outpudstream, RobotomyRequestForm const &obj)
{
    outpudstream << "RobotomyRequestForm under the name of " << obj.getName() << endl;
    return (outpudstream);
}