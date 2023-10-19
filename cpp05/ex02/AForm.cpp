/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:58:12 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:55:56 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_name("default"), _sign(false), _signGrade(150), _execGrade(150){
    std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(std::string const & name, int const signGrade, int const execGrade)
        : _name(name), _sign(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "AForm Constructor called" << std::endl;
    if (signGrade > 150 || execGrade > 150){
        throw(GradeTooLowException());
    }
    else if (signGrade < 1 || execGrade < 1){
        throw(GradeTooHighException());
    }
}

//catch an exception for if NULL is passed to name
AForm::AForm(std::string const * name, int const signGrade, int const execGrade) 
        : _name(""), _sign(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "AForm Null Constructor called" << std::endl;
    if (name == NULL || name->empty()){
        throw NullStringException();
    }
    (void)signGrade;
    (void)execGrade;
}

AForm::AForm(AForm const & other)
    : _name(other._name), _sign(other._sign), _signGrade(other._signGrade), _execGrade(other._execGrade){
         std::cout << "AForm Copy Constructor called" << std::endl;
    }

AForm & AForm::operator=(AForm const & other){
    std::cout << "AForm Copy Assignment Constructor called" << std::endl;
    if (this != &other) {
		const_cast<std::string&>(_name) = other._name;
		_sign = other._sign;
        const_cast<int&>(_signGrade) = other._signGrade;
        const_cast<int&>(_execGrade) = other._execGrade;
	}
	return *this;
}

AForm::~AForm(){
    std::cout << "AForm Destructor called" << std::endl;
}

std::string const & AForm::getName()const{ return _name; }

int AForm::getSignGrade()const{ return _signGrade; }

bool AForm::getSign()const{ return _sign; }

int AForm::getExecGrade()const { return _execGrade; }

const char * AForm::GradeTooHighException::what() const throw(){
     return RED "Grade is too high" DEFAULT;
}

const char * AForm::GradeTooLowException::what() const throw(){
    return RED "Grade is too low" DEFAULT;
}

const char * AForm::NullStringException::what() const throw(){
    return RED "A Null string was passed" DEFAULT;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << GREEN << "AForm: " << form.getName() << std::boolalpha << ", signed: " << form.getSign() << ", grade required to sign: "
        << form.getSignGrade() << ", grade required to execute: " << form.getExecGrade() << DEFAULT;
    return (os);
}

void AForm::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() <= _signGrade){
        _sign = true;
    }
    else {
        throw GradeTooLowException();
    }
}