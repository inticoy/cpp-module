/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:33:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 16:00:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &ct);
  ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &ct);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  std::string name_;
  int hit_;
  int energy_;
  int attack_damage_;
};

#endif