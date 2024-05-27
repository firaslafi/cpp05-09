/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:36 by flafi             #+#    #+#             */
/*   Updated: 2024/05/27 20:22:23 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &source)
{
	*this = source;
}

RPN &RPN::operator=(const RPN &source)
{
	if (this == &source)
		return (*this);
	return (*this);
}

void RPN::performOperation(char operation, stack<int> &operands)
{
	int	operand1;
	int	operand2;
	int	result;

	operand1 = operands.top();
	operands.pop();
	operand2 = operands.top();
	operands.pop();
	switch (operation)
	{
	case '+':
		result = operand2 + operand1;
		break ;
	case '-':
		result = operand2 - operand1;
		break ;
	case '*':
		result = operand2 * operand1;
		break ;
	case '/':
		result = operand2 / operand1;
		break ;
	default:
		cerr << "Unsupported operation" << std::endl;
	}
	operands.push(result);
}

void RPN::calculateRPN(const string &expression)
{
	// stack<int> _stack;
	for (size_t index = 0; index < expression.length(); ++index)
	{
		if (expression[index] == ' ')
		{
			continue ;
		}
		if (isdigit(expression[index]))
		{
			_stack.push(expression[index] - '0');
		}
		else if (expression[index] == '+' || expression[index] == '-'
			|| expression[index] == '*' || expression[index] == '/')
		{
			performOperation(expression[index], _stack);
		}
		else
		{
			cerr << "Error: Invalid character '" << expression[index] << "' encountered in the expression." << endl;
			return ;
		}
	}
	if (!_stack.empty())
	{
		cout << _stack.top() << endl;
	}
	else
	{
		cerr << "Error: No operands in stack to display" << endl;
	}
}