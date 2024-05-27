/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:33 by flafi             #+#    #+#             */
/*   Updated: 2024/05/27 20:15:10 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */ // for ANIMAL
#define YELLOW  "\033[33m"      /* Yellow */ // for CAT
#define BLUE    "\033[34m"      /* Blue */ 
#define MAGENTA "\033[35m"      /* Magenta */ // for brain
#define CYAN    "\033[36m"      /* Cyan */ // for DOG
#define WHITE   "\033[37m"      /* White */
#define RESET   "\033[0m"       /* Reset color */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::cout;
using std::endl;
using std::stack;
using std::cerr;

class RPN
{
private:
    stack<int> _stack;
public:
    RPN(void);
    ~RPN(void);
    
    RPN(const RPN &source);
    RPN &operator=(const RPN &source);
    
    void calculateRPN(const string &expression);
    void performOperation(char operation, stack<int>& operands);
};



#endif