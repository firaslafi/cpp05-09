/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:59:05 by flafi             #+#    #+#             */
/*   Updated: 2024/05/18 20:53:13 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

// default constructor
Span::Span(void) : _n(0)
{}

Span::Span(unsigned int n) : _n(n)
{
}

Span::~Span(void)
{
}

// copy constructor
Span::Span(const Span &src)
{
    if (this != &src)
    {
        this->_n = src._n;
        this->_vec = src._vec;
    }
    else throw Span::SelfAssignmentException();
}

// assignation operator
Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _n = src._n;
        _vec = src._vec;
    }
    else throw Span::SelfAssignmentException();
    return (*this);
}

void Span::addNumber(unsigned int number)
{
    if (_vec.size() >= _n)
        throw MaxElementReachedException();
    _vec.push_back(number);
}

// you need to loop through all the members
// its forbiden to find the biggest and smallest number then substract them or add them
int Span::shortestSpan(void)
{
    if (_vec.size() <= 1)
        throw NoSpanException();
    std::sort(_vec.begin(), _vec.end());
    int min = std::abs(_vec[1] - _vec[0]);
    for (int i = 1; i < _vec.size(); i++)
    {
        if (_vec[i] - _vec[i - 1] < min)
            min = _vec[i] - _vec[i - 1];
    }
    return std::abs(min);
}
// different approch but same results within the constraints of the subject 
int Span::longestSpan()
{
    if (_vec.size() <= 1)
        throw NoSpanException();
    int min = _vec[0];
    int max = _vec[0];
    for (size_t i = 1; i < _vec.size(); ++i) 
    {
        if (_vec[i] < min)
            min = _vec[i];
        if (_vec[i] > max)
            max = _vec[i];
    }
    return (max - min);
}
void Span::randomNumbersFiller(unsigned int n)
{
    srand(time(0));
    for (unsigned int i = 0; i < n; i++)
        addNumber(rand());
}

// exception
const char *Span::MaxElementReachedException::what() const throw()
{
    return "Max element reached";
}

const char *Span::NoSpanException::what() const throw()
{
    return "No span to find";
}

const char *Span::SelfAssignmentException::what() const throw()
{
    return "Self assignment";
}

