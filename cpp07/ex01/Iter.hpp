/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:17:16 by desteve           #+#    #+#             */
/*   Updated: 2023/09/24 00:40:12 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"

template< typename T >
void print( T const & x ) { std::cout << GREEN << x << DEFAULT << std::endl; return; }

template <typename T>
void iter(T arr[], size_t arrlen, void (*arrFunc)(T const &)){
    for (size_t i = 0; i < arrlen; i++){
        arrFunc(arr[i]);
    }
}

#endif