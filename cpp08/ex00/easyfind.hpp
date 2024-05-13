/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:18:05 by flafi             #+#    #+#             */
/*   Updated: 2024/05/14 00:15:16 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>


using std::cout;
using std::endl;

template <typename T> void easyfind(T &container, int value)
{
    if (std::find(container.begin(), container.end(), value) == container.end())
        cout << "value not found!" << endl;
    else
        cout << "value has been detected!" << endl;
}

#endif
