/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:39:53 by desteve           #+#    #+#             */
/*   Updated: 2023/09/13 16:39:56 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "data.hpp"

int main()
{
    Data data = {1, 2, 3};

    uintptr_t serialized = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized data: " << deserialized->a << ", " << deserialized->b << ", " << deserialized->c << std::endl;

    if (deserialized == &data) {
        std::cout << GREEN << "Pointer comparison successful" << DEFAULT << std::endl;
        std::cout << GREEN << deserialized << std::endl;
        std::cout << &data <<  DEFAULT << std::endl;
        std::cout <<  YELLOW << data.a <<  std::endl;
        std::cout <<  data.b <<  std::endl;
        std::cout <<  data.c <<  DEFAULT << std::endl;
    } else {
        std::cout << RED << "Pointer comparison failed" << DEFAULT << std::endl;
    }

    return 0;
}
