/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:02:38 by flafi             #+#    #+#             */
/*   Updated: 2024/05/13 22:52:42 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
// not possible
// ScalarConverter(const ScalarConverter &source)
// {

// }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source)
{
	return (*this);
}

bool isChar(const std::string &s) {
    return (s.length() == 1 && isalpha(s[0]));
}
bool isInteger(const std::string &s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char *p;
    long long val = strtoll(s.c_str(), &p, 10);
    return *p == '\0' && val >= INT_MIN && val <= INT_MAX;
}
// Check if every character is a digit, a decimal point, or if it's a valid negative/positive sign
bool isFloat(const std::string &s) {
    if (s.empty()) return false;

    bool hasDecimal = false;
    bool hasF = false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (!isdigit(c) && c != '-' && c != '+' && c != '.') {
            if ((c == 'f' || c == 'F') && !hasF && hasDecimal && i == s.size() - 1) {
                hasF = true;
            } else {
                return false;
            }
        } else if (c == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        }
    }
    return true;
}
bool isDouble(const std::string &s) {
    if (s.empty()) return false;

    bool hasDecimal = false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (!isdigit(c) && c != '.') {
            return false;
        } else if (c == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        }
    }
    return true;
}
void ScalarConverter::convert(const string target)
{
	// convertFloat(target);
    if (isChar(target))
    {
        convertChar(target);
    }
    else if (isInteger(target))
    {
        convertInt(target);
    }
    else if (isFloat(target))
    {
        convertFloat(target);
    }
    else if (isDouble(target))
    {
        convertDouble(target);
    }
    else if (isnan(std::stod(target)) || isinf(std::stod(target)))
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: " << target << "f" << endl;
		cout << "double: " << target << endl;
	}
	else
	{
		cout << "Invalid input" << endl;
	}

}
// this function is under construction need to be implemented
bool ScalarConverter::isvalidInput(const string &target)
{
	if (!target.compare("inf") || !target.compare("-inf")
		|| !target.compare("+inf") || !target.compare("nan")
		|| !target.compare("inff") || !target.compare("-inff")
		|| !target.compare("+inff") || !target.compare("nanf"))
		return (true);
	return (false);
}

void ScalarConverter::convertChar(const string &target)
{
	char	charFormat;
	int		intFormat;
	float	floatFormat;
	double	doubleFormat;

	charFormat = target[0];
	intFormat = static_cast<int>(charFormat);
	floatFormat = static_cast<float>(charFormat);
	doubleFormat = static_cast<double>(charFormat);
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
	int		intFormat;
	float	floatFormat;
	double	doubleFormat;

	// char charFormat;
	intFormat = std::stoi(target);
	floatFormat = static_cast<float>(intFormat);
	doubleFormat = static_cast<double>(intFormat);
    if (intFormat >= 32 && intFormat <= 126)
        cout << "char: '" << static_cast<char>(intFormat) << "'" << endl;
    else
        cout << "char: unprintable" << endl;
    
	cout << "int: " << intFormat << endl;
	cout << "float: " << floatFormat << ".0f" << endl;
	cout << "double: " << doubleFormat << ".0" << endl;
}

// in float or double we need to handle inf and nan
void ScalarConverter::convertFloat(const string &target)
{
	float	floatFormat;
	double	doubleFormat;

	try
	{
		floatFormat = std::stof(target);
	}
	catch (const std::out_of_range &)
	{
		std::cerr << "Input out of range: " << target << std::endl;
		return ;
	}
    if (floatFormat < 32 || floatFormat > 126)
        cout << "char: unprintable" << endl;
    else
        cout << "char: '" << static_cast<char>(floatFormat) << "'" << endl;
    cout << "int: " << static_cast<int>(floatFormat) << endl;

	if (isinf(floatFormat) || isnan(floatFormat))
	{
		cout << "float: impossible" << endl;
		if (floatFormat == (int)floatFormat)
			cout << "double: " << floatFormat << ".0" << endl;
		else
			cout << "double: " << floatFormat << endl;
		return ;
	}
	if (floatFormat > FLT_MAX || floatFormat < FLT_MIN)
	{
		cout << "float: impossible" << endl;
		if (floatFormat == (int)floatFormat)
			cout << "double: " << floatFormat << ".0" << endl;
		else
			cout << "double: " << floatFormat << endl;
	}
	else
	{
		if(floatFormat == (int)floatFormat)
			cout << "float: " << floatFormat << ".0f" << endl;
		else
			cout << "float: " << floatFormat << "f" << endl;
		if (floatFormat == (int)floatFormat)
			cout << "double: " << floatFormat << ".0" << endl;
		else
			cout << "double: " << floatFormat << endl;
	}
}

void ScalarConverter::convertDouble(const string &target)
{
	double	doubleFormat;
	float	floatFormat;

	try
	{
		doubleFormat = std::stod(target);
		floatFormat = static_cast<float>(doubleFormat);
		cout << "char: unprintable" << endl;
		cout << "int: unprintable" << endl;
		if (isinf(floatFormat) || isnan(floatFormat))
		{
			cout << "float: " << floatFormat << "f" << endl;
		}
		else
		{
			cout << "float: "<< "impossible" << endl;
		}
		if (doubleFormat > DBL_MAX || doubleFormat < DBL_MIN)
		{
			cout << "double: "<< "impossible" << endl;
		}
		else
		{
			cout << "double: " << doubleFormat << endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "stod conversion failed: " << e.what() << '\n';
	}
}
