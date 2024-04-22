/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:26 by flafi             #+#    #+#             */
/*   Updated: 2024/04/22 13:27:42 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"
# include "./Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat nelson("Nelson", 1);
        nelson.decrementGrade();
        Form anmeldung("anmeldung", 5, 1);
        
        // cout << nelson;
        // cout << anmeldung;
        nelson.signForm(anmeldung);
        nelson.signForm(anmeldung);
        
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
    }
    return (0);
}