/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:22:51 by desteve           #+#    #+#             */
/*   Updated: 2023/10/13 00:12:38 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>



class PmergeMe
{
	public:
	PmergeMe(int ac, char **av);
	template <typename T>
	void display(const T& container);
	void mergeInsertSortDeque(std::deque<int>& arr);
	void mergeInsertSortList(std::list<int>& arr);
};

template <typename Iterator>
Iterator my_prev(Iterator it, int n = 1) {
    while (n > 0) {
        --it;
        --n;
    }
    return it;
}