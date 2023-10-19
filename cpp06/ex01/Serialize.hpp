/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:40:41 by desteve           #+#    #+#             */
/*   Updated: 2023/09/13 20:45:35 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

#define DEFAULT	"\033[0m"
#define YELLOW 	"\e[0;33m"
#define GREEN	"\033[1;32m"
#define CYAN	"\033[0;36m"
#define RED 	"\e[0;31m"

struct Data;

class Serializer
{
    private: 
        Serializer();
		Serializer(int a,int b,int c);
        ~Serializer();
        Serializer(const Serializer & other);
        Serializer & operator=(const Serializer & other);
    public:
        static uintptr_t serialize(Data * ptr);
        static Data * deserialize(uintptr_t raw);
};

#endif

/*
  Putting the constructor, destructor and operator private makes the 
  class Serializer effectively a static class, because it cannot 
  be instantiated or copied. 
  To call the static methods of the class, we use 
  the scope resolution operator ::, like this:
  uintptr_t serializedData = Serializer::serialize(myDataPtr);
  Data* deserializedData = Serializer::deserialize(serializedData);
  
  The serializer and deserializer are functions that convert an object 
  or data structure into a format that can be transmitted or stored, 
  and then recreate the original object or data structure from the serialized format.
*/