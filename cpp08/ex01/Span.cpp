/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:34:02 by desteve           #+#    #+#             */
/*   Updated: 2023/09/24 03:36:02 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N): _N(N), _data() { _data.reserve(N); }

Span::Span(Span const & other) : _N(other._N), _data(other._data) {}

Span const & Span::operator=(Span const & other){
    if (this != &other){
        _N = other._N;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_data.size() == _N) {
        throw std::out_of_range(RED "Span is full, cannot add more elements" DEFAULT);
    }
    _data.push_back(value);
}

unsigned int Span::shortestSpan(){
    if (_data.size() < 2){
        throw std::out_of_range(RED "No Span can be found" DEFAULT );
    }
    std::vector<int> sorted_nums(_data);
    std::sort(sorted_nums.begin(), sorted_nums.end());

    int min_distance = INT_MAX;
    for(size_t i = 1; i < sorted_nums.size(); ++i){
        int diff = sorted_nums[i] - sorted_nums[i - 1];
        if (diff < min_distance)
            min_distance = diff;
    }
    return min_distance;
}

unsigned int Span::longestSpan() {
    if (_data.size() < 2) {
        throw std::out_of_range(RED "No Span can be found" DEFAULT);
    }

    int min_element = *std::min_element(_data.begin(), _data.end());
    int max_element = *std::max_element(_data.begin(), _data.end());
    return (max_element - min_element);
}

void Span::printNumbers(){
    std::cout << GREEN << "Array Numbers: ";
     for (unsigned int i = 0; i < _data.size(); i++){
            std::cout << _data[i] << " ";
        }
        std::cout << std::endl;
}