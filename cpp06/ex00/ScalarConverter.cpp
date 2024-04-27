/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:02:38 by flafi             #+#    #+#             */
/*   Updated: 2024/04/27 14:51:56 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}
// not possible
// ScalarConverter(const ScalarConverter &source)
// {
    
// }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &source)
{
    return (*this);
}

void ScalarConverter::convert(const string target)
{
    convertChar(target);
}
bool ScalarConverter::isvalidInput(const string &target)
{
    if (!target.compare("inf") || !target.compare("-inf") || !target.compare("+inf") || !target.compare("nan") ||
        !target.compare("inff") || !target.compare("-inff") || !target.compare("+inff") || !target.compare("nanf"))
        return (true);
    
    return (false);
}

void ScalarConverter::convertChar(const string &target)
{
    char charFormat;
    int intFormat;
    float floatFormat;
    double doubleFormat;

    charFormat = target[0];
    intFormat = static_cast<int> (charFormat);
    floatFormat = static_cast<float> (charFormat);
    doubleFormat = static_cast<double> (charFormat);

    cout << "char :";
    if (isprint(charFormat))
        cout << "'" << charFormat << "'" << endl;
    else
        cout << "unprintable" << endl;
    cout << "int: " << intFormat << endl;
    cout << "float: " << floatFormat << ".0f" << endl;
    cout << "double: " << doubleFormat << ".0" << endl;
}
