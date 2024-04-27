/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:02:41 by flafi             #+#    #+#             */
/*   Updated: 2024/04/27 14:10:52 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
// for isprint
#   include <cctype>
using std::string;
using std::cout;
using std::endl;

class ScalarConverter
{
    private:
    // the constructor is made private to make it uninstanciable 
    ScalarConverter(void);

    // the static methodes
    static void convertChar(const string &target);
    static void convertInt(const string &target);
    static void convertFloat(const string &target);
    static void convertDouble(const string &target);
    
    public:
    ~ScalarConverter(void);
    
    // copy assign and copy operator
    ScalarConverter(const ScalarConverter &source);
    ScalarConverter &operator=(const ScalarConverter &source);

    static void convert(const string target);
};

#endif