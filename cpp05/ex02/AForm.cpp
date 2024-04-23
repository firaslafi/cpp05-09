/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:20:52 by flafi             #+#    #+#             */
/*   Updated: 2024/04/23 16:28:48 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

Form::Form(void) : _name("defaultName"), _gradeToSign(1), _gradeToExcute(1)
{
	this->_signed = false;
	cout << "Default constructor called for a From, grades set at 1." << endl;
}
// desired constructor
Form::Form(const string &name, int gradeToSign,
	int gradeToExcute) : _name(name), _gradeToSign(gradeToSign),
	_gradeToExcute(gradeToExcute)
{
	if (_gradeToSign < 1 || _gradeToExcute < 1)
		throw GradeTooLowException();
	if (_gradeToSign > 150 || _gradeToExcute > 150)
		throw GradeTooHighException();
	this->_signed = false;
}
Form::~Form(void)
{
}

// copy assign and copy operator
Form::Form(const Form &source) : _name(source._name),
	_gradeToSign(source._gradeToSign), _gradeToExcute(source._gradeToExcute)
{
}
// other members are const means tyou are allowed to change them
Form& Form::operator=(const Form &source)
{
	if (this != &source)
	{
		this->_signed = source._signed;
	}
	return (*this);
}
void Form::beSigned(const Bureaucrat &bureaucratObj)
{
	if (bureaucratObj.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
}
// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("Form isn't signed");
}

// getters
string Form::getName(void) const
{
	return (this->_name);
}
bool Form::getSigned(void) const
{
	return (this->_signed);
}
int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}
int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExcute);
}
std::ostream &operator<<(std::ostream &outpudstream, Form const &obj)
{
	outpudstream << "Form name: " << obj.getName() << endl;
	outpudstream << "Grade to sign: " << obj.getGradeToSign() << endl;
	outpudstream << "Grade to execute: " << obj.getGradeToExecute() << endl;
	outpudstream << "Signed: " << obj.getSigned() << endl;
	return (outpudstream);
}
