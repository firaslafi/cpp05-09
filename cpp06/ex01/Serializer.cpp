/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:51:00 by flafi             #+#    #+#             */
/*   Updated: 2024/05/05 19:02:00 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"

Serializer::Serializer(/* args */)
{
}

Serializer::~Serializer()
{
}
Serializer::Serializer(const Serializer &source)
{
    (void)source;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
Serializer &Serializer::operator=(const Serializer &source)
{
    (void)source;
    return (*this);
}