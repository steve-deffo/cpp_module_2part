/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:26:26 by desteve           #+#    #+#             */
/*   Updated: 2023/09/28 19:07:15 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

//checks the container for the value and returns -1 if not found
//returns the index if found


template<typename T>
int easyfind(T & container, int value){
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        return (-1);
    return (std::distance(container.begin(), it));
}

#endif