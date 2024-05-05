/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:51:02 by flafi             #+#    #+#             */
/*   Updated: 2024/05/05 20:35:03 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include "./Data.hpp"
# include <iostream>
# include <string>

using std::cout;

class Serializer
{
private:
    Serializer(void);
    ~Serializer(void);
    
    Serializer(const Serializer &source);
    Serializer &operator=(const Serializer &source);
    

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};



#endif