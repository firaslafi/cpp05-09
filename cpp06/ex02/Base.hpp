/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:28 by flafi             #+#    #+#             */
/*   Updated: 2024/05/05 21:31:15 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <iostream> 

using std::cout;
using std::endl;

class Base
{
private:
    /* data */
public:
    // making the destructor virtual to enable polymorphism and could be defined in the inherited classes
    virtual ~Base(void);
    static Base* generate(void);
    static void identify(Base* p);
    static void identify(Base& p);
};


#endif