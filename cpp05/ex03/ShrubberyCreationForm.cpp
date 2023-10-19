/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:31 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:59:42 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default"){
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

//catch an exception for if NULL is passed to target
ShrubberyCreationForm::ShrubberyCreationForm(std::string const * target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target("") {
    std::cout << "ShrubberyCreationForm Null Constructor called" << std::endl;
    if (target == NULL || target->empty()){
        throw NullStringException();
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other): AForm(other), _target(other._target) {
         std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other){
    std::cout << "ShrubberyCreationForm Copy Assignment Constructor called" << std::endl;
    if (this != &other) {
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
    if (getSign() == true && executor.getGrade() <= getExecGrade())
	{
		std::ofstream file;
		file.open((_target + "_shrubbery").c_str());
		file << TREE << std::endl;
		file.close();
	}
	else if (executor.getGrade() <= getExecGrade())
	{
		throw GradeTooLowException();
	}
	else
	{
		throw std::out_of_range(RED "Bureaucrat cannot execute this form" DEFAULT);
	}
}