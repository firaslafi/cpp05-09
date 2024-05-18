/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:59:04 by flafi             #+#    #+#             */
/*   Updated: 2024/05/18 20:50:01 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
    private:
    unsigned int _n;
    std::vector<int> _vec;
    
    public:
    Span(void);
    Span(unsigned int n);
    ~Span(void);
    
    // copy constructor and assignation operator
    Span(const Span &src);
    Span &operator=(const Span &src);

    void addNumber(unsigned int number);
    int shortestSpan(void);
    int longestSpan(void);
    void randomNumbersFiller(unsigned int n);
    
    // exception
    class MaxElementReachedException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };
    class NoSpanException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };
    class SelfAssignmentException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };
};

#endif