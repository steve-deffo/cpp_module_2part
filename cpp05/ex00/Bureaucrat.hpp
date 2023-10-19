/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:36:48 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 15:56:12 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define DEFAULT	"\033[0m"
#define YELLOW 	"\e[0;33m"
#define GREEN	"\033[1;32m"
#define CYAN	"\033[0;36m"
#define RED 	"\e[0;31m"

class Bureaucrat{
    private:
        std::string const _name;
        int _grade;
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
        
        Bureaucrat();
        Bureaucrat(Bureaucrat const & other);
        Bureaucrat & operator=(Bureaucrat const & other);
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(std::string const * name, int grade);
        ~Bureaucrat();

        std::string const & getName()const;
        int getGrade()const;

        void incrementGrade();
        void decrementGrade();
};
std::ostream & operator<<(std::ostream & os, Bureaucrat const & b);