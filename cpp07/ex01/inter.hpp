/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:40:52 by flafi             #+#    #+#             */
/*   Updated: 2024/05/09 18:48:07 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
# define INTER_HPP

# include <iostream>

template <typename Type> void inter(Type *array, size_t arr_len, void (*f)(Type &))
{
	size_t	i;

	i = 0;
	while (i < arr_len)
	{
		f(array[i]);
		i++;
	}
}

#endif