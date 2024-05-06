/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:59:36 by flafi             #+#    #+#             */
/*   Updated: 2024/05/06 17:39:19 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Base.hpp"

int main(void)
{
    Base* first = Base::generate();
    
    Base::identify(first);
    Base::identify(*first);
    return (0);
}