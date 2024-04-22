/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:42:12 by flafi             #+#    #+#             */
/*   Updated: 2024/04/22 13:00:18 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"
class Bureaucrat;

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
	Form(const string &name, int gradeToSign, int gradeToExcute);

    // copy assign and copy operator
	Form(const Form &source);
	Form &operator=(const Form &source);

    string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

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