/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:24:21 by flafi             #+#    #+#             */
/*   Updated: 2024/05/22 23:52:11 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

void BitcoinExchange::readDataFile(const string &filename)
{
	std::ifstream dataFile(filename);
	if (!dataFile.is_open())
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return ;
	}
	string line;
	while (std::getline(dataFile, line))
	{
		size_t pos = line.find(',');
		// if (pos == string::npos)
		// {
		// 	std::cerr << "Error: invalid data format" << std::endl;
		// }
		// else
		// {
		// }
		string date = line.substr(0, pos);
		double rate = std::stod(line.substr(pos + 1));
		_exchangeRate.insert({date, rate});
		// std::cout << line << std::endl;
	}
	dataFile.close();
}
BitcoinExchange::BitcoinExchange(void)
{
	readDataFile("data.csv");
}
BitcoinExchange::BitcoinExchange(string filename)
{
	readDataFile(filename);
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