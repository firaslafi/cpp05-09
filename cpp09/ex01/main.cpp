/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:41 by flafi             #+#    #+#             */
/*   Updated: 2024/05/27 20:20:19 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cerr << "Usage: ./RPN " << RED << " \"expression\"" << RESET << endl;
		return (1);
	}
	RPN rpn;
	rpn.calculateRPN(av[1]);
	return (0);
}