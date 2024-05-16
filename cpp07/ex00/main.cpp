/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:41:31 by flafi             #+#    #+#             */
/*   Updated: 2024/05/16 18:31:06 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./whatever.hpp"

class complex
{
	public:
	complex() : a(0), b(0) {};
	complex(int a, int b) : a(a), b(b) {};
	~complex() {};
	int a;
	int b;
	
	bool operator==(const complex &object) const
	{
		return (a == object.a && b == object.b);
	}
	bool operator>(const complex &object) const
	{
		return (a > object.a && b > object.b);
	}
	bool operator<(const complex &object) const
	{
		return (a < object.a && b < object.b);
	}
	
};

int	main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	complex test1(1, 2);
	complex test2(3, 4);
	::swap(test1, test2);
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "test1.a = " << test1.a << ", test1.b = " << test1.b << std::endl;
	std::cout << "test2.a = " << test2.a << ", test2.b = " << test2.b << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "min(test1, test2)= " << ::min(test1, test2).a << std::endl;
	std::cout << "max(test1, test2) = " << ::max(test1, test2).a << std::endl;
	
	return (0);
}