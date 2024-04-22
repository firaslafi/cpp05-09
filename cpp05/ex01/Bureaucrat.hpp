/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:24 by flafi             #+#    #+#             */
/*   Updated: 2024/04/22 12:54:47 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
# include <exception>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

# include "./Form.hpp"
class Form;

class Bureaucrat
{
  private:
	const string _name;
	int _grade;

  public:
	Bureaucrat(void);
	~Bureaucrat(void);

	// desired constructor
	Bureaucrat(const string &name, int grade);

	// copy assign and copy operator
	Bureaucrat(const Bureaucrat &source);
	Bureaucrat &operator=(const Bureaucrat &source);

	string getName() const;
	int getGrade() const;

	// Exception classes
	class GradeTooHighException : public std::exception
	{
		public:
    
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
    
		virtual const char *what() const throw();
	};
	void incrementGrade();
	void decrementGrade();

	void signForm(Form& form);
};

// overloading the << operator for COUT so it can print something
std::ostream &operator<<(std::ostream &outpudstream, Bureaucrat const &obj);
#endif