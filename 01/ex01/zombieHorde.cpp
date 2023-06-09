/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:19:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 21:54:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombie = new Zombie[N];  // allocate zombie array
  for (int i = 0; i < N; i++) {
    zombie[i].set_name(name + std::to_string(i + 1));
  }
  return zombie;
}