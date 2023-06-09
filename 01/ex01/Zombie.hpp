/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:30:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:11:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce();
  void set_name(std::string name);
  const std::string &get_name() const;

private:
  std::string name_;
};

Zombie *zombieHorde(int N, std::string name);

#endif
