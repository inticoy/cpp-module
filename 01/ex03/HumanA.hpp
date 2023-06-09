/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:48 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:13:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {
public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();
  void attack();

private:
  Weapon &weapon_;
  std::string name_;
};

#endif
