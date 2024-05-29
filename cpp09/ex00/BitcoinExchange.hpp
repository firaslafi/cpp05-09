/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:24:18 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 22:36:05 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
// fstream includes both output and input stream
# include <fstream>
#include <iomanip>
// # include <sstream>

using std::map;
using std::string;
using std::cout;
using std::endl;

#define BTCMAXSUPPLY 21000000
class BitcoinExchange
{
private:
    map<string, double> _exchangeRate;
    map<string, double> _database;
public:
    BitcoinExchange(void);
    BitcoinExchange(string filename);
    ~BitcoinExchange(void);

    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange &operator=(const BitcoinExchange &source);
    
    void readDataFile(const string &filename);
    int checkDate(const string &date);
    void getExchangeRate(const string &date, const double &amount);
    void readDatabaseCSV(void);
    
    // void printData(void)
    // {
    //     cout << "Map DATA:" << endl;
    //     cout << "--------------------------------" << endl;
    //     for (map<string, double>::iterator it = _database.begin(); it != _database.end(); it++)
    //     {
    //         std::cout << it->first << " " << it->second << std::endl;
    //     }
    // }
};


#endif