/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 22:09:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called.\n";
    type = "Cat";
    brain = new Brain();
    brain->addIdea("I want some fresh fish!");
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "Cat Copy Constructor called.\n";
    type = cat.type;
    brain = new Brain(*cat.brain);
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called.\n";
    delete brain;
}
Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat Assignment Operator called.\n";
    type = cat.type;
    Brain *newBrain = new Brain(*cat.brain);
    delete brain;
    brain = newBrain;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows~\n";
}

void Cat::addIdea(const std::string &idea) const
{
    brain->addIdea(idea);
}

void Cat::delIdea() const
{
    brain->delIdea();
}

void Cat::printIdeas() const
{
    brain->printIdeas();
}