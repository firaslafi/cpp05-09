/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:40:49 by flafi             #+#    #+#             */
/*   Updated: 2024/05/16 18:35:03 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

// Test function for integers
void printInt(int& num)
{
    std::cout << num << " ";
}

// Test function for characters
void printChar(char& ch)
{
    std::cout << ch << " ";
}

template <typename Type> void templatePrintString(Type &str)
{
    std::cout << str << " ";
}

int main()
{
    // Test case 1: Array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLen = sizeof(intArray) / sizeof(int);
    std::cout << "Printing integers: ";
    iter(intArray, intArrayLen, printInt);
    std::cout << std::endl;

    // Test case 2: Array of characters
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLen = sizeof(charArray) / sizeof(char);
    std::cout << "Printing characters: ";
    iter(charArray, charArrayLen, printChar);
    std::cout << std::endl;
    
    // Test case 3: Array of strings
    std::string strArray[] = {"Hello", "Everyone", "From","42", "Heilbronn!"};
    size_t strArrayLen = sizeof(strArray) / sizeof(std::string);
    std::cout << "Printing strings: ";
    iter(strArray, strArrayLen, templatePrintString);
    std::cout << std::endl;
    
    return 0;
}