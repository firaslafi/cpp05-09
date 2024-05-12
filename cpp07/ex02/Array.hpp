/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:58:48 by flafi             #+#    #+#             */
/*   Updated: 2024/05/12 23:10:11 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename Type> class Array
{
private:
    Type *_array;
    unsigned int _size;
public:
    Array(void)
    {
        _array = NULL;
        _size = 0;
    }
    Array(unsigned int n)
    {
        _array = new Type[n];
        _size = n;
        for(unsigned int i = 0; i < n; i++)
            _array[i] = 0
    }
    ~Array(void);
    
    Array(Array const &src);
    Array &operator=(Array const &src);

    unsigned int size(void) const;
    
    class IndexOutOfBoundException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };
};




#endif