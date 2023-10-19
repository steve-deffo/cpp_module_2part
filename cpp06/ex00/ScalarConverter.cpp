/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:50:50 by desteve           #+#    #+#             */
/*   Updated: 2023/09/04 00:38:44 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::is_pseudo_literal(std::string & s) {
    return s == "nan" || s == "nanf" || s == "+inf" || s == "inf" || s == "-inf"
            || s == "+inff" || s == "inff" || s == "-inff";
}

void ScalarConverter::convert_to_char(std::string &s) {
    if (is_pseudo_literal(s)) {
        std::cout << RED << "Impossible" << DEFAULT << std::endl;
        return ;
    }
    char c = static_cast<char>(atoi(s.c_str()));
    if (!std::isprint(c)) {
        std::cout << RED << "Non displayable" << DEFAULT << std::endl;
        return ;
    }
    std::cout << GREEN << c << DEFAULT << std::endl;
}

void ScalarConverter::convert_to_int(std::string &s) {
    if (is_pseudo_literal(s)) {
        std::cout << RED << "Impossible" << DEFAULT << std::endl;
        return ;
    }
    long long value = std::atoll(s.c_str());
    if (value > INT_MAX || value < INT_MIN) {
        std::cout << RED << "Impossible" << DEFAULT << std::endl;
    } else {
        std::cout << GREEN << static_cast<int>(value) << DEFAULT << std::endl;
    }
}

void ScalarConverter::convert_to_float(std::string &s) {
    char* end;
    float nbr = std::strtof(s.c_str(), &end);

    //  check if the float value has no decimal part.
    if (*end == '\0' && nbr - static_cast<int>(nbr) == 0) {
        std::cout << GREEN << nbr << ".0f" << DEFAULT << std::endl;
        return ;
    }
    std::cout << GREEN << nbr << "f" << DEFAULT << std::endl;
}

void ScalarConverter::convert_to_double(std::string &s) {
    char * end;
    double nbr = std::strtod(s.c_str(), &end);

    //  check if the double value has no decimal part.
    if (*end == '\0' && nbr - static_cast<int>(nbr) == 0) {
        std::cout << GREEN << nbr << ".0" << DEFAULT << std::endl;
        return ;
    }
    std::cout << GREEN << nbr << DEFAULT << std::endl;
}

void ScalarConverter::convert(std::string &s) {
    std::cout << "char: ", convert_to_char(s);
    std::cout << "int: ", convert_to_int(s);
    std::cout << "float: ", convert_to_float(s);
    std::cout << "double: ", convert_to_double(s);
}   

bool ScalarConverter::is_valid(std::string &s) {
    if (is_pseudo_literal(s))
        return true;

    // if s is a character, convert it to its ascii value
    if (s.length() == 1 && isalpha(s[0])) {
        std::stringstream ss;
        ss << static_cast<int>(s[0]);
        s = ss.str();
        return true;
    }

    for (std::string::size_type i = 0; i < s.size(); i++) {
        char c = s[i];
        // checks if c is a digit (0-9), a decimal point (.), 
        // a sign (+ or -), or a floating point suffix (f)
        if (!isdigit(c) && c != '+' && c != '-' && c != 'f' && c != '.') {
            return false;
        }
    }
    return true;
}



/*
    "nan" - represents a NaN (not a number) value
    "nanf" - represents a NaN (not a number) value with a float suffix
    "+inf" - represents positive infinity
    "inf" - represents positive or negative infinity
    "-inf" - represents negative infinity
    "+inff" - represents positive infinity with a float suffix
    "inff" - represents positive or negative infinity with a float suffix
    "-inff" - represents negative infinity with a float suffix
*/