/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:20:34 by desteve           #+#    #+#             */
/*   Updated: 2023/08/24 20:07:09 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat steve("steve", 2);
	Bureaucrat deffo("deffo", 149);

	try
	{
		std::cout << steve << std::endl;
		std::cout << deffo << std::endl;
		steve.incrementGrade();
		deffo.decrementGrade();
		std::cout << steve << std::endl;
		std::cout << deffo << std::endl;
		steve.incrementGrade();
		deffo.decrementGrade();
		std::cout << steve << std::endl;
		std::cout << deffo << std::endl;
	}
	catch(const std::exception& dns)
	{
		std::cerr << dns.what() << std::endl;
	}
}