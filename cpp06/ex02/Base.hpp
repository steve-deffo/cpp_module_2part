/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:30:15 by desteve           #+#    #+#             */
/*   Updated: 2023/09/04 04:32:43 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"

#include <iostream>
#include <cstdlib>
#include <ctime>


class Base {
public:
    virtual ~Base() {}
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#endif

/*
Dynamic casts are evaluated at runtime and 
requires a virtual function in the base class
Dynamic casts check if a derived class object 
can be safely cast to a base class pointer. 
dynamic casts check if the object being cast is 
an instance of the base class or one of its derived classes.
If the object is not of the correct type, 
the dynamic cast will return a null pointer.
*/