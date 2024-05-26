/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:33 by flafi             #+#    #+#             */
/*   Updated: 2024/05/26 19:11:54 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::cout;
using std::endl;
using std::stack;

class RPN
{
private:
    stack<int> _stack;
public:
    RPN(/* args */);
    ~RPN();
};

RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}


#endif