/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:06:11 by flafi             #+#    #+#             */
/*   Updated: 2024/04/27 14:09:07 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "wrong number of arguments" << endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}