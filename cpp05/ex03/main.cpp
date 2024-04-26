/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:26 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 16:15:21 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./PresidentialPardonForm.hpp"
# include "./Intern.hpp"

int main(void)
{
    try
    {
        // Bureaucrat ash("ash", 2);

        // RobotomyRequestForm myform("veryimportantform");
        // PresidentialPardonForm presform("presdiental form");
        
        // ash.signForm(myform);
        // ash.executeForm(myform);
        // ash.signForm(presform);
        // ash.executeForm(presform);
        
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
    }
    return (0);
}