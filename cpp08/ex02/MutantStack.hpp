/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:43:00 by desteve           #+#    #+#             */
/*   Updated: 2023/09/24 03:44:00 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define DEFAULT		"\033[0m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
    MutantStack();
    MutantStack(MutantStack const & other);
    MutantStack & operator=(MutantStack const & other);
    ~MutantStack();
    
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();

};

#include "MutantStack.tpp"
#endif