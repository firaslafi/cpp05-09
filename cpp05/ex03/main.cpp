/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:26 by flafi             #+#    #+#             */
/*   Updated: 2024/04/24 15:03:04 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat ash("ash", 2);

        RobotomyRequestForm myform("veryimportantform");
        PresidentialPardonForm presform("presdiental form");
        
        ash.signForm(myform);
        ash.executeForm(myform);
        ash.signForm(presform);
        ash.executeForm(presform);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
    }
    return (0);
}