/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:26:30 by desteve           #+#    #+#             */
/*   Updated: 2023/09/24 03:30:38 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
    std::vector<int> my_vector;

    my_vector.push_back(10);
    my_vector.push_back(20);
    my_vector.push_back(30);
    my_vector.push_back(20);
    my_vector.push_back(50);

    std::cout << YELLOW << "Test for the first Occurence of a Valid Value" << DEFAULT << std::endl;
    int value = easyfind(my_vector, 30);
    if ( value == -1 ){
            std::cout << RED << "Value not found" << DEFAULT << std::endl;
    }
    else {
            std::cout << GREEN << "Value at index: " << value << DEFAULT << std::endl;
    }

    std::cout << YELLOW << "Test for a Value not in the List" << DEFAULT << std::endl;
    value = easyfind(my_vector, 70);
    if ( value == -1 ){
            std::cout << RED << "Value not found" << DEFAULT << std::endl;
    }
    else {
            std::cout << GREEN << "Value at index: " << value << DEFAULT << std::endl;
    }

    std::cout << YELLOW << "Insert Value at the beggining and Check for Value" << DEFAULT << std::endl;
    my_vector.insert(my_vector.begin(), 30);
    
    value = easyfind(my_vector, 30);
    if ( value == -1 ){
            std::cout << RED << "Value not found" << DEFAULT << std::endl;
    }
    else {
            std::cout << GREEN << "Value at index: " << value << DEFAULT << std::endl;
    }

    return (0);
}