/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:07:21 by desteve           #+#    #+#             */
/*   Updated: 2023/08/30 16:58:16 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        std::string _target;
    public: 
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const & other);
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(std::string const * target);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & other);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat& executor) const;
};

#endif