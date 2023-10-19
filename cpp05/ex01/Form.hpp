/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:08:01 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:00:22 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form{
    private:
        std::string const _name;
        bool _sign;
        int const _signGrade;
        int const _execGrade;
    public: 
    
        class GradeTooHighException: public std::exception
        {
            public:  
                virtual const char * what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:  
                virtual const char * what() const throw();
        };
        class NullStringException: public std::exception
        {
            public:  
                virtual const char * what() const throw();
        };

        Form();
        Form(Form const & other);
        Form & operator=(Form const & other);
        Form(std::string const & name, int const signGrade, int const execGrade);
        Form(std::string const * name, int const signGrade, int const execGrade);
        ~Form();

        std::string const & getName()const;
        bool getSign()const;
        int getSignGrade()const;
        int getExecGrade()const;

        void beSigned(Bureaucrat const & bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);
#include "Bureaucrat.hpp"

#endif