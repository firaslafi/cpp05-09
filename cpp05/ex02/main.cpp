/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:26 by flafi             #+#    #+#             */
/*   Updated: 2024/04/23 16:53:38 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"
# include "./ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat bureau("ash", 2);
        ShrubberyCreationForm a("paper");
        
        bureau.signForm(a);
        bureau.executeForm(a);
        
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
    }
    return (0);
}