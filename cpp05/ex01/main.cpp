/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:31:26 by flafi             #+#    #+#             */
/*   Updated: 2024/04/21 14:08:45 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat Nelson("Nelson", 1);
        Nelson.incrementGrade();
        cout << Nelson;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
    }
    return (0);
}