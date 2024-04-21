/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:25 by flafi             #+#    #+#             */
/*   Updated: 2024/04/21 14:02:23 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"

//  Constructors
Bureaucrat::Bureaucrat(void): _name("defaultName")
{
    this->_grade = 150;
    cout << "Default constructor called. Default values are set.";
}
/*initializing the name with the inializer list is pereferred for
const members, but the body assigment is perefered when there is a conditional
initializing in this case throwing expections*/
// Constructor
Bureaucrat::Bureaucrat(const string &name, int grade): _name(name)
{
    if (grade < 1)
        throw GradeTooLowException();
    if (grade > 150)
        throw GradeTooHighException();
    this->_grade = grade;
}

//  Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &source): _name(source._name), _grade(source._grade)
{
    
}
// Copy Assign Operator
Bureaucrat& Bureaucrat::operator= (const Bureaucrat &source)
{
    if (this != &source)
    {
        this->_grade = source._grade;
    }
    return (*this);
}
// Increment grade
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    else
        _grade--;
}

// Decrement grade
void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    else
        _grade++;
}
//  Destructor
Bureaucrat::~Bureaucrat(void)
{
    // cout << "Default destructor called.";
}
string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return(_grade);
}
// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high, pick a value between 1,150");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low, pick a value between 1,150");
}
// overriding the << operator for the outputstream
ostream &operator<<(ostream &outpudstream, Bureaucrat const &object)
{
    outpudstream << object.getName() << ", bureaucrat grade " << object.getGrade() << endl;
    return (outpudstream);
}