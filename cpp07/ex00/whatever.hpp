/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:50:33 by desteve           #+#    #+#             */
/*   Updated: 2023/09/23 21:54:43 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"


template <typename T>

T const & max(T const & x, T const & y){
    return (x >= y ? x : y );
}

template <typename T>

T const & min(T const & x, T const & y){
    return (x <= y ? x : y );
}

template <typename T>

void swap(T & x, T & y){
    T temp =  x;
    x = y;
    y = temp;
}

#endif