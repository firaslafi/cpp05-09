/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:58:50 by flafi             #+#    #+#             */
/*   Updated: 2024/05/12 23:52:30 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    try {
    
    // testing constructor
    Array<int> arr(20);
    // testing operator[]
    arr[4] = 42;
    // verifying if it has been set
    std::cout << arr[4] << std::endl;
    
    // testing copy constructor
    Array<int> arr2(arr);
    // verifying if it has been copied  
    std::cout << arr2[4] << std::endl;
    
    // testing assignment operator
    Array<int> arr3 = arr;
    // verifying if it has been copied
    std::cout << arr3[4] << std::endl;

    // testing out of range
    // arr[5] = 42;
    // arr[-6] = 42;
    
    // testing empty array
    Array<int> arr4;
    // arr4[0] = 42;
    // std::cout << arr4[0] << std::endl;
    
    arr[1] = 99;
    arr3[4] = arr[1];
    std::cout << arr3[4] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // system("leaks program");
    return (0);
}