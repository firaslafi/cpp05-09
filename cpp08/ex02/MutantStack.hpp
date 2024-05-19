/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:45:34 by flafi             #+#    #+#             */
/*   Updated: 2024/05/19 22:56:52 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <deque>
# include <list>

template <typename Type>
class MutantStack : public std::stack<Type>
{
    // private:
    
    public:
    MutantStack(void) : std::stack<Type>() {}
    // virutal destructor is needed to avoid undefined behavior with different types
    virtual ~MutantStack(void) {}
    
    MutantStack(const MutantStack &source) : std::stack<Type>(source) {}
    MutantStack &operator=(const MutantStack &source)
    {
        if (this == &source)
            return (*this);
        std::stack<Type>::operator=(source);
        return (*this);
    }

    // itertors
    typedef typename std::deque<Type>::iterator iterator;
    iterator begin(void)
    {
        return (std::stack<Type>::c.begin());
    }
    iterator end(void)
    {
        return (std::stack<Type>::c.end());
    }
    
};
#endif