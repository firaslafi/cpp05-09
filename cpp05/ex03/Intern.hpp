/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:08 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 15:47:26 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
# include <exception>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

# include "./AForm.hpp"
class Intern
{
    public:
    
    Intern(void);
    ~Intern(void);

    Intern(const Intern &source);
    Intern& operator=(const Intern &source);
    
    Form* makeForm(string name, string target);
    
};
#endif