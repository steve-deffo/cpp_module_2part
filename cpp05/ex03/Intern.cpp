/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:10:46 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 17:11:03 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern Default Constructor called" << std::endl;
    this->funcPtr[0] = &Intern::makeShrubberyForm;
    this->funcPtr[1] = &Intern::makeRobotomyForm;
    this->funcPtr[2] = &Intern::makePresidentialForm;
}

Intern::Intern(const Intern & other){
    std::cout << "Intern Copy Constructor called" << std::endl;
    *this = other;
}

Intern & Intern::operator=(const Intern & other){
    std::cout << "AForm Copy Assignment Constructor called" << std::endl;
    (void)other;
    return (*this);
}

Intern::~Intern(){
    std::cout << "Intern Destructor called" << std::endl;
}

AForm * Intern::makeShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm * Intern::makeRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm * Intern::makePresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string const & formName, std::string const & formTarget){
    std::string forms[3] = { "Shrubbery Creation",
                             "Robotomy Request",
                             "Presidential Pardon"};
    
    for(int i = 0; i < 3; i++) {
        if (forms[i] == formName){
            std::cout << GREEN << "Intern creates " << formName << DEFAULT << std::endl;
            return ((this->*funcPtr[i])(formTarget));
        }
    }
    std::cout << RED << "This Form is Non-Existent" << DEFAULT << std::endl;
    return (0);
}