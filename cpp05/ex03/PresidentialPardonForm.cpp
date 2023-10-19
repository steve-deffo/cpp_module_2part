/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:16 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:57:58 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default"){
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

//catch an exception for if NULL is passed to target
PresidentialPardonForm::PresidentialPardonForm(std::string const * target) 
    : AForm("PresidentialPardonForm", 25, 5), _target("") {
    std::cout << "PresidentialPardonForm Null Constructor called" << std::endl;
    if (target == NULL || target->empty()){
        throw NullStringException();
    }
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other): AForm(other), _target(other._target) {
         std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other){
    std::cout << "PresidentialPardonForm Copy Assignment Constructor called" << std::endl;
    if (this != &other) {
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    if (getSign() == true && executor.getGrade() <= getExecGrade())
	{
		std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox" DEFAULT << std::endl;
	}
	else if (executor.getGrade() <= getExecGrade()) {
		throw GradeTooLowException();
	}
	else {
		throw std::out_of_range(RED "Bureaucrat cannot execute this form" DEFAULT);
	}
}