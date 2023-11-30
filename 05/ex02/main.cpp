/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 17:05:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    {
        std::cout << "TEST 1" << '\n';
        AForm *form = new ShrubberyCreationForm("test");
        Bureaucrat president("Kim", 1);
        Bureaucrat servant("Lee", 150);

        servant.executeForm(*form);
        president.executeForm(*form);
        servant.signForm(*form);
        president.signForm(*form);
        servant.executeForm(*form);
        president.executeForm(*form);

        delete form;
    }

    {
        std::cout << '\n' << "TEST 2" << '\n';
        AForm *form = new RobotomyRequestForm("gyoon");
        Bureaucrat president("Kim", 1);
        Bureaucrat servant("Lee", 150);

        servant.executeForm(*form);
        president.executeForm(*form);
        servant.signForm(*form);
        president.signForm(*form);
        servant.executeForm(*form);
        for (int i = 0; i < 4; i++)
        {
            president.executeForm(*form);
        }

        delete form;
    }

    {
        std::cout << '\n' << "TEST 3" << '\n';
        AForm *form = new PresidentialPardonForm("gyoon");
        Bureaucrat president("Kim", 1);
        Bureaucrat servant("Lee", 150);

        servant.executeForm(*form);
        president.executeForm(*form);
        servant.signForm(*form);
        president.signForm(*form);
        servant.executeForm(*form);
        president.executeForm(*form);

        delete form;
    }

    return 0;
}
