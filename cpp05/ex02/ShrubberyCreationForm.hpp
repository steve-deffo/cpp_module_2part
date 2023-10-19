/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:35 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 17:00:13 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

#define TREE        "\033[1;32m       ,@@@@@@@,\
\n                  ,,,.   ,@@@@@@/@@,  .oo8888o.\
\n               ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\
\n              ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\
\n              %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\
\n              %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\
\n              `&%\\ ` /%&'    |.|        \\ '|8'\
\n                  |o|        | |         | |\
\n                  |.|        | |         | |\
\n               \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\033[0m\n"


class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;
    public: 
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const & other);
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(std::string const * target);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat& executor) const;
};

#endif