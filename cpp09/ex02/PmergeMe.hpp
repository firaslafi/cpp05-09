/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:31 by flafi             #+#    #+#             */
/*   Updated: 2024/05/27 20:30:35 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &source);
    PmergeMe &operator=(const PmergeMe &source);

    // void merge(std::vector<int> &v1, std::vector<int> &v2);
    // void printVector(const std::vector<int> &v);
};
#endif