/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:02:38 by flafi             #+#    #+#             */
/*   Updated: 2024/05/02 20:11:03 by flafi            ###   ########.fr       */
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
    // convertChar(target);
    // convertInt(target);
    // convertFloat(target);
    convertDouble(target);
}
// this function is under construction need to be implemented
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

    cout << "char:";
    if (isprint(charFormat))
        cout << "'" << charFormat << "'" << endl;
    else
        cout << "unprintable" << endl;
    cout << "int: " << intFormat << endl;
    cout << "float: " << floatFormat << ".0f" << endl;
    cout << "double: " << doubleFormat << ".0" << endl;
}
void ScalarConverter::convertInt(const string &target)
{
    // char charFormat;
    int intFormat;
    float floatFormat;
    double doubleFormat;
    
    intFormat = std::stoi(target);
    floatFormat = static_cast<float> (intFormat);
    doubleFormat = static_cast<double> (intFormat);
    
    cout << "char: unprintable" << endl;
    cout << "int: " << intFormat << endl;
    cout << "float: " << floatFormat << ".0f" << endl;
    cout << "double: " << doubleFormat << ".0" << endl;
}

// in float or double we need to handle inf and nan
void ScalarConverter::convertFloat(const string &target)
{
    float floatFormat;
    double doubleFormat;
    
    cout << "char: unprintable" << endl;
    cout << "int: unprintable" << endl;
    
    if (isvalidInput(target))
    {
        if (floatFormat > FLT_MAX || floatFormat < FLT_MIN)
        {
            cout << "float: " << "impossible" << endl;
        }
        cout << "float: " << target << "f" << endl;
        cout << "double: " << target << endl;
        return ;
    }
    
    floatFormat = std::stof(target);
    doubleFormat = static_cast<double> (floatFormat);
    
    
    cout << "float: " << floatFormat << ".0f" << endl;
    cout << "double: " << doubleFormat << ".0" << endl;
    
}

void ScalarConverter::convertDouble(const string &target)
{
    double doubleFormat;
    
    doubleFormat = std::stod(target);
    
    cout << "char: unprintable" << endl;
    cout << "int: unprintable" << endl;
    
    if (isvalidInput(target))
    {
        cout << "float: " << doubleFormat << "f" << endl;
        cout << "double: " << doubleFormat << endl;
    }
    else 
    {
        cout << "float: unprintable" << endl;
        cout << "double: " << doubleFormat << ".0" << endl;
    }
}