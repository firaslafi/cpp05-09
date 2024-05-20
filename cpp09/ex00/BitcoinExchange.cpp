/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:24:21 by flafi             #+#    #+#             */
/*   Updated: 2024/05/20 21:24:12 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	string	line;

	std::ifstream dataFile("data.csv");
    std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		std::cout << line << std::endl;
	}
	dataFile.close();
}
BitcoinExchange::~BitcoinExchange(void)
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
{
	*this = source;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
	if (this == &source)
		return (*this);
	return (*this);
}