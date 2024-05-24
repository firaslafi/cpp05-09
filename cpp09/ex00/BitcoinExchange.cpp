/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:24:21 by flafi             #+#    #+#             */
/*   Updated: 2024/05/24 19:00:25 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"



int BitcoinExchange::checkDate(const std::string &date)
{
	std::string year = date.substr(0, 4);
	int yearValue = std::stoi(year);
	// leap yearlogic
	bool	isLeapYear = ((yearValue % 4 == 0 && yearValue % 100 != 0) || yearValue % 400 == 0);
	size_t		maxDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (isLeapYear)
		maxDaysInMonth[1] = 29;
		
	if (yearValue < 1900 || yearValue > 3000)
		return 0;

	std::string day = date.substr(8, 2);
	int dayValue = std::stoi(day);
	
	std::string month = date.substr(5, 2);
	int monthValue = std::stoi(month);
	
	if (dayValue < 1 || dayValue > maxDaysInMonth[monthValue - 1])
		return 0;

	if (monthValue < 1 || monthValue > 12)
		return 0;

	return 1;
}
void BitcoinExchange::readDataFile(const std::string &filename)
{
	size_t	pos;
	double	amount;

	std::ifstream dataFile(filename);
	if (!dataFile.is_open())
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return ;
	}
	std::string line;
	std::getline(dataFile, line);
	int i = 1; // testing purposes
	while (std::getline(dataFile, line))
	{
		// cout << i++ << endl;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		
		std::string date = line.substr(0, pos - 1);
		if (!checkDate(date))
		{
			std::cerr << "Error: bad date => " << date << std::endl;
			continue ;
		}
		amount = std::stod(line.substr(pos + 2));
		// maybe sperate it
		if (amount > BTCMAXSUPPLY)
		{
			std::cerr << "Error: too large a number."<< endl;
			continue ;
		}
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number."<< endl;
			continue ;
		}
		// maybe sperate it
		cout << date << " => " << amount << endl;
		std::pair<std::string, double> exchangeRateEntry(date, amount);
		_exchangeRate.insert(exchangeRateEntry);

	}
	dataFile.close();
}
BitcoinExchange::BitcoinExchange(void)
{
	// readDataFile("data.csv");
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