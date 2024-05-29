/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:24 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 20:55:33 by flafi            ###   ########.fr       */
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

	p.FJSort(p.arr);
	for (int i = 0; i < p.arr.size(); i++)
		cout << p.arr[i] << " ";
	cout << endl;
	return (0);
}