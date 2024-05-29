/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:24 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 22:14:48 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << RED << "./PmergeMe \"num list\"" << RESET << std::endl;
		return (1);
	}

	PmergeMe p(argc, argv);

    p.printVectorFormat(p.arr);
    p.printFormatdeque(p.arrdeque);
	return (0);
}
// make re && ./PmergeMe `jot -r 10 1 1000 | tr '\n' ' '`