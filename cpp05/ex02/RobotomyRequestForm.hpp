/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:28 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:59:20 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private:
        std::string _target;
    public: 
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const & other);
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(std::string const * target);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& executor) const;
};

#endif