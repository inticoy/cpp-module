/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:43:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 15:13:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &pf);
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &pf);

    virtual void execute(const Bureaucrat &e) const
        throw(GradeTooLowException, NotSignedException);

  private:
    std::string target;
};

#endif