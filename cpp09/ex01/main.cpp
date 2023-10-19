/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:20:45 by desteve           #+#    #+#             */
/*   Updated: 2023/10/06 03:20:57 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalide argument." << std::endl;
		return (1);
	}
	std::stack<int> rpn;
	int a, b;
	for (int i = 0; av[1][i]; i++)
	{
		if (isOperator(av[1][i]))
		{
			if (rpn.size() < 2)
			{
				std::cout << "Error: invalide argument." << std::endl;
				return (1);
			}
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			rpn.push(opertion(a, b, av[1][i]));
		}
		else if (isValidNumber(av[1][i]))
		{
			if (isValidNumber(av[1][i + 1]))
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			rpn.push(av[1][i] - 48);
		}
		else if (av[1][i] != ' ')
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}
	std::cout << rpn.top() << std::endl;
}