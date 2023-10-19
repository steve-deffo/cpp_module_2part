/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:02 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:56:24 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#define DEFAULT	"\033[0m"
#define YELLOW 	"\e[0;33m"
#define GREEN	"\033[1;32m"
#define CYAN	"\033[0;36m"
#define RED 	"\e[0;31m"

#include <iostream>
class Bureaucrat;

class AForm{
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

        AForm();
        AForm(AForm const & other);
        AForm & operator=(AForm const & other);
        AForm(std::string const & name, int const signGrade, int const execGrade);
        AForm(std::string const * name, int const signGrade, int const execGrade);
        virtual ~AForm();

        std::string const & getName()const;
        bool getSign()const;
        int getSignGrade()const;
        int getExecGrade()const;

        void beSigned(Bureaucrat const & bureaucrat);

        virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#include "Bureaucrat.hpp"

#endif