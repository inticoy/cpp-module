/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:45:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/15 21:56:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
  public:
    class GradeTooHighException : public std::exception
    {
      private:
        std::string msg;

      public:
        GradeTooHighException();
        virtual ~GradeTooHighException() throw();
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      private:
        std::string msg;

      public:
        GradeTooLowException();
        virtual ~GradeTooLowException() throw();
        const char *what() const throw();
    };

    Form();
    Form(const Form &f);
    Form(const std::string &name);
    Form(const std::string &name, const unsigned char &minSignGrade,
         const unsigned char &minExeGrade) throw(GradeTooHighException,
                                                 GradeTooLowException);
    virtual ~Form();
    Form &operator=(const Form &f);

    const std::string &getName() const;
    const unsigned char &getMinSignGrade() const;
    const unsigned char &getMinExeGrade() const;
    const bool &getIsSigned() const;

    bool beSigned(const Bureaucrat &b) throw(GradeTooLowException);

    friend std::ostream &operator<<(std::ostream &os, const Form &f);

  private:
    const std::string name;
    const unsigned char minSignGrade;
    const unsigned char minExeGrade;
    bool isSigned;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif