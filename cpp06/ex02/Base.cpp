/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:03:23 by flafi             #+#    #+#             */
/*   Updated: 2024/05/05 21:27:51 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "./Base.hpp"
#include "C.hpp"

Base::~Base(void)
{
}

Base*	Base::generate(void)
{
	int	random;

	srand(time(0));
	random = rand() % 3;
	if (random == 0)
	{
		cout << "A generated" << endl;
		return (new A);
	}
	else if (random == 1)
	{
		cout << "B generated" << endl;
		return (new B);
	}
	else
	{
		cout << "C generated" << endl;
		return (new C);
	}
}
/* the dynamic_cast operator is used to ensure that the pointer is pointing to the correct object
if the pointer is pointing to the correct object,
	the dynamic_cast operator returns a pointer to the object aka true
if the pointer is not pointing to the correct object,
	the dynamic_cast operator returns a nullptr aka false
yup, as simple as that*/
void	Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B *>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C *>(p))
		cout << "C" << endl;
}

void	Base::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		cout << "A" << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		cout << "B" << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		cout << "C" << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}