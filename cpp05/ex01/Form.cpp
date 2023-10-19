/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:08:05 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 15:59:35 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_name("default"), _sign(false), _signGrade(150), _execGrade(150){
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string const & name, int const signGrade, int const execGrade)
        : _name(name), _sign(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "Form Constructor called" << std::endl;
    if (signGrade > 150 || execGrade > 150){
        throw(GradeTooLowException());
    }
    else if (signGrade < 1 || execGrade < 1){
        throw(GradeTooHighException());
    }
}

//catch an exception for if NULL is passed to name
Form::Form(std::string const * name, int const signGrade, int const execGrade) 
        : _name(""), _sign(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << "Form Null Constructor called" << std::endl;
    if (name == NULL || name->empty()){
        throw NullStringException();
    }
    (void)signGrade;
    (void)execGrade;
}

Form::Form(Form const & other)
    : _name(other._name), _sign(other._sign), _signGrade(other._signGrade), _execGrade(other._execGrade){
         std::cout << "Form Copy Constructor called" << std::endl;
    }

Form & Form::operator=(Form const & other){
    std::cout << "Form Copy Assignment Constructor called" << std::endl;
    if (this != &other) {
		const_cast<std::string&>(_name) = other._name;
		_sign = other._sign;
        const_cast<int&>(_signGrade) = other._signGrade;
        const_cast<int&>(_execGrade) = other._execGrade;
	}
	return *this;
}

Form::~Form(){
    std::cout << "Form Destructor called" << std::endl;
}

std::string const & Form::getName()const{ return _name; }

int Form::getSignGrade()const{ return _signGrade; }

bool Form::getSign()const{ return _sign; }

int Form::getExecGrade()const { return _execGrade; }

const char * Form::GradeTooHighException::what() const throw(){
     return RED "Grade is too high" DEFAULT;
}

const char * Form::GradeTooLowException::what() const throw(){
    return RED "Grade is too low" DEFAULT;
}

const char * Form::NullStringException::what() const throw(){
    return RED "A Null string was passed" DEFAULT;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << GREEN << "Form: " << form.getName() << std::boolalpha << ", signed: " << form.getSign() << ", grade required to sign: "
        << form.getSignGrade() << ", grade required to execute: " << form.getExecGrade() << DEFAULT;
    return (os);
}

void Form::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() <= _signGrade){
        _sign = true;
    }
    else {
        throw GradeTooLowException();
    }
}