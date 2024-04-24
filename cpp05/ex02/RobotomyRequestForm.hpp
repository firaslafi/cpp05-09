/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:23 by flafi             #+#    #+#             */
/*   Updated: 2024/04/24 14:46:20 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

# include "./AForm.hpp"

class RobotomyRequestForm: public Form
{
    private:
    string _target;
    public:
    
    // constructors
    RobotomyRequestForm(void);
    RobotomyRequestForm(string target);
    ~RobotomyRequestForm(void);
    
    // copy assign and copy operator
    RobotomyRequestForm(const RobotomyRequestForm &source);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
    
    void execute(Bureaucrat const & executor) const;
    
};

// overloading the << operator for COUT so it can print something
std::ostream &operator<<(std::ostream &outpudstream, RobotomyRequestForm const &obj);

#endif