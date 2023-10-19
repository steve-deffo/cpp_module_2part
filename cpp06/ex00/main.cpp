/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 23:02:29 by desteve           #+#    #+#             */
/*   Updated: 2023/09/04 00:33:45 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main() {
    std::string input;
    ScalarConverter converter;

    std::cout << YELLOW << "Enter a value to convert: " << DEFAULT;
    std::getline(std::cin, input);

    if (!converter.is_valid(input)) {
        std::cout << RED << "Invalid input" << DEFAULT << std::endl;
        return 1;
    }

    converter.convert(input);
    return 0;
}