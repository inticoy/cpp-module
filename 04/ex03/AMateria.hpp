/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:19:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 19:00:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>
#include <string>

class AMateria
{
  protected:
    std::string type;

  public:
    AMateria();
    AMateria(const AMateria &m);
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &a);

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif