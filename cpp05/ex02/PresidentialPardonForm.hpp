/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:18 by flafi             #+#    #+#             */
/*   Updated: 2024/04/23 15:58:46 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM
#define PRESIDENTALPARDONFORM

# include "./Aform.hpp"

class PresidentialPardonForm: public Form
{
    private:
    string _target;
    public:
    
    // constructors
    PresidentialPardonForm(void);
    PresidentialPardonForm(string target);
    ~PresidentialPardonForm(void);
    
    // copy assign and copy operator
    PresidentialPardonForm(const PresidentialPardonForm &source);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
    
    void execute(Bureaucrat const & executor) const;
    
};

// overloading the << operator for COUT so it can print something
std::ostream &operator<<(std::ostream &outpudstream, PresidentialPardonForm const &obj);

#endif