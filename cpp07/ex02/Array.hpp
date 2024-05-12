/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:58:48 by flafi             #+#    #+#             */
/*   Updated: 2024/05/12 23:48:13 by flafi            ###   ########.fr       */
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
        // there is no need to check becaue unsigned int is always positive
        _array = new Type[n];
        _size = n;
        for(unsigned int i = 0; i < n; i++)
            _array[i] = 0;
    }
    ~Array(void)
    {
        if (_array)
            delete [] _array;
    }
    
    Array(Array const &src)
    {
        _size = src.size();
        _array = new Type[_size];
        for(unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }
    
    Array &operator=(Array const &src)
    {
        if (this == &src)
            return *this;
        // if it has already been allocated and got some data in it, delete it
        if (_array)
            delete [] _array;
        // redoing the same as initialization with unsigned int n constructor
        _size = src.size();
        _array = new Type[_size];
        for(unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
        return *this;
    }

    unsigned int size(void) const
    {
        return this->_size;
    }
    
    class IndexOutOfBoundException : public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return "Index out of bound exception";
        }
    };
    Type &operator[](unsigned int i) const
    {
        if (i >= _size || i < 0)
            throw IndexOutOfBoundException();
        return _array[i];
    }
};




#endif