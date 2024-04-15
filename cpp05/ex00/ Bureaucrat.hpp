/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:24 by flafi             #+#    #+#             */
/*   Updated: 2024/04/15 04:45:39 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat
{
  private:
	const string _name;
	int _grade;
  
  public:
  
  Bureaucrat(void);
  ~Bureaucrat(void);
  
  Bureaucrat(const Bureaucrat &source);
  Bureaucrat& operator= (const Bureaucrat &source);
  
  string getName() const;
  int    getGrade() const;

  void incrementGrade();
  void decrementGrade();
  
};

// overloading the << operator for COUT so it can print something
std::ostream &operator<<( std::ostream &outpudstream, Bureaucrat const &obj);
#endif