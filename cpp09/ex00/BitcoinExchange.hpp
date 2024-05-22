/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:24:18 by flafi             #+#    #+#             */
/*   Updated: 2024/05/22 23:37:12 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
// fstream includes both output and input stream
# include <fstream>
// # include <sstream>

using std::map;
using std::string;

class BitcoinExchange
{
private:
    map<string, double> _exchangeRate;
public:
    BitcoinExchange(void);
    BitcoinExchange(string filename);
    ~BitcoinExchange(void);

    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange &operator=(const BitcoinExchange &source);
    
    void readDataFile(const string &filename);
};


#endif