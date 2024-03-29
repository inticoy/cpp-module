/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 15:10:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Gil-Dong"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name,
                       int grade) throw(GradeTooHighException,
                                        GradeTooLowException)
    : name(name)
{
    setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        grade = other.grade;
    return *this;
}

const std::string &Bureaucrat::getName() const { return name; }

const int &Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::setGrade(int grade) throw(GradeTooHighException,
                                           GradeTooLowException)
{
    if (grade < 1)
        throw GradeTooHighException(grade);
    else if (grade > 150)
        throw GradeTooLowException(grade);
    else
        this->grade = grade;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    if (grade == 1)
        throw GradeTooHighException(grade);
    else
        --grade;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    if (grade == 150)
        throw GradeTooLowException(grade);
    else
        ++grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat has grade " << b.getGrade();
    return os;
}
