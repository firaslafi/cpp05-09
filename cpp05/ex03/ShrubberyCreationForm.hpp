/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:29 by flafi             #+#    #+#             */
/*   Updated: 2024/04/23 16:52:08 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

# include "./AForm.hpp"

class ShrubberyCreationForm: public Form
{
    private:
    string _target;
    public:
    
    // constructors
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(string target);
    ~ShrubberyCreationForm(void);
    
    // copy assign and copy operator
    ShrubberyCreationForm(const ShrubberyCreationForm &source);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
    
    void execute(Bureaucrat const & executor) const;
    
};

// overloading the << operator for COUT so it can print something
std::ostream &operator<<(std::ostream &outpudstream, ShrubberyCreationForm const &obj);

#endif