/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:42:12 by flafi             #+#    #+#             */
/*   Updated: 2024/04/21 15:12:01 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"
#include <exception>
#include <iostream>

using std::string;

#ifndef FORM_HPP
# define FORM_HPP

class Form
{
  private:
	const string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExcute;

  public:
	Form(void);
	~Form(void);

	// desired constructor
	Form(void);

    // copy assign and copy operator
	Form(const Form &source);
	Form &operator=(const Form &source);

    string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExcute() const;

    void beSigned(const Bureaucrat& bureaucratObj);
    
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
    
};

// overloading the << operator for COUT so it can print something
std::ostream &operator<<(std::ostream &outpudstream, Form const &obj);

#endif