/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:24:15 by flafi             #+#    #+#             */
/*   Updated: 2024/05/22 23:53:36 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./bitcoin data.csv" << std::endl;
        return (1);
    }
    BitcoinExchange exchange(argv[1]);
    // run here
    std::cout << "Exchange rate for 2024-05-21: " << exchange["2024-05-21"] << std::endl;
    return (0);
}