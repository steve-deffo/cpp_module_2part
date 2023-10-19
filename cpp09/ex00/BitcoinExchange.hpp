/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:32:14 by desteve           #+#    #+#             */
/*   Updated: 2023/10/13 00:07:22 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <string>
# include <cstdlib>


std::map<std::string, double> readcsv();
bool isValideDate(std::string date);
bool checkDot(std::string value);
void getResult(std::map<std::string, double> &btc);

#endif