/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:18:03 by flafi             #+#    #+#             */
/*   Updated: 2024/05/14 00:16:18 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;

    for (int i = 1; i <= 20; i++) 
    {
        vec.push_back(i);
    }
    
    
    easyfind(vec, 5);
    easyfind(vec, 42);
    return 0;
}