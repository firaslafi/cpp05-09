/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:59:04 by flafi             #+#    #+#             */
/*   Updated: 2024/05/17 23:17:40 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class span
{
    private:
    unsigned int _n;
    std::vector<int> _vec;
    
    public:
    span(void);
    span(unsigned int n);
    ~span(void);
    
    // copy constructor and assignation operator
    span(const span &src);
    span &operator=(const span &src);

    void addNumber(unsigned int number);
    int shortestSpan(void);
    int longestSpan(void);
    
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
};

#endif