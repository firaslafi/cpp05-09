/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:28:03 by flafi             #+#    #+#             */
/*   Updated: 2024/05/09 18:38:54 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Type> void swap(Type &a, Type &b)
{
	Type	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename Type> Type min(Type &a, Type &b)
{
	if (a == b)
		return (b);
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename Type> Type max(Type &a, Type &b)
{
	if (a == b)
		return (b);
	if (a > b)
		return (a);
	else
		return (b);
}

#endif