/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:20:54 by desteve           #+#    #+#             */
/*   Updated: 2023/09/25 13:56:40 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[1;4;33m"



template<typename T>
class Array{
    private:
        T * _arr;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const & other);
        Array const & operator=(Array const & other);
        ~Array();

        T & operator[]( unsigned int const index);//M
        T const & operator[]( unsigned int const index)const;//L
        unsigned int size()const;
};


#include "Array.tpp"

#endif