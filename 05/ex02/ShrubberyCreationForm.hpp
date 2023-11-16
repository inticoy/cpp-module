/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/16 21:09:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &scf);
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &scf);

    virtual bool execute(const Bureaucrat &e) const throw(GradeTooLowException);

  private:
    std::string target;
};

#endif