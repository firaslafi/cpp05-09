/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:45:28 by flafi             #+#    #+#             */
/*   Updated: 2024/05/19 23:05:54 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	// std::list<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
    // we cannot use begin and end functions from std::stack because 
    // by design you can access only top element of stack
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::cout << "---------------------" << std::endl;
	/***************************************************/
	// an other member function from stack is swap
	std::stack<int> stackTwo;
	stackTwo.push(42);
	stackTwo.push(43);
	stackTwo.push(44);
	stackTwo.push(45);
	mstack.swap(stackTwo);
	it = mstack.begin();
	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	/***************************************************/
	// std::list<int> mlist;
    
    // mlist.push_back(5);
    // mlist.push_back(17);
    // std::cout << mlist.back() << std::endl;
    // mlist.pop_back();
    // std::cout << mlist.size() << std::endl;
    // mlist.push_back(3);
    // mlist.push_back(5);
    // mlist.push_back(737);
    // mlist.push_back(0);

    // std::list<int>::iterator it = mlist.begin();
    // std::list<int>::iterator ite = mlist.end();
    // ++it;
    // --it;
    // while (it != ite) {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::list<int> s(mlist);
	
	return (0);
}