/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:43:24 by flafi             #+#    #+#             */
/*   Updated: 2024/05/05 20:36:01 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"
#include "./Data.hpp"

int main()
{
    Data *data = new Data;
    data->text = "Hello";
    data->n = 424242;
    
    uintptr_t the_int = Serializer::serialize(data);
    Data *desrializedData = Serializer::deserialize(the_int);
    
    if ( desrializedData->text == data->text && desrializedData->n == data->n )
        std::cout << "Data is conversed" << std::endl;
    else
        std::cout << "Data is corrupted" << std::endl;
    
    cout << "proof of usability:" << std::endl;
    cout << "Text: " << desrializedData->text << std::endl;
    cout << "Number: " << desrializedData->n << std::endl;
    delete data;
    return (0);
}
