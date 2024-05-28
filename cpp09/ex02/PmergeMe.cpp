/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:28 by flafi             #+#    #+#             */
/*   Updated: 2024/05/28 19:57:47 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &source)
{
    *this = source;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
    if (this == &source)
        return (*this);
    return (*this);
}