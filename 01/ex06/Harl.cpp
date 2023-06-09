/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 14:36:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

const std::string Harl::kLevels[LVLS] = {"DEBUG", "INFO", "WARNING", "ERROR",
                                         ""};

const std::string Harl::kComments[LVLS] = {
    "I love having extra bacon for my "
    "7XL-double-chess-triple-pickle-special-ketchup burger.\n"
    "I really do !",
    "I cannot believe adding extra bacon costs more money.\n"
    "You didn't put enough bacon in my burger!\n"
    "If you did, I wouldn't be asking for more!",
    "I think I deserve to have some extra bacon for free.\n"
    "I've been coming for yeears whereas you started working "
    "here since last month.",
    "This is unacceptable!\n"
    "I want to speak to the manager now.",
    "[Probably complaining about insignificant problems]"};

Harl::Harl() {
  fp[kDebug] = &Harl::debug;
  fp[kInfo] = &Harl::info;
  fp[kWarning] = &Harl::warning;
  fp[kError] = &Harl::error;
  fp[kUndefined] = &Harl::undefined;
}
Harl::~Harl() {}

/* other ways :
 * void (Harl::*fp[5])() = {...}; or
 * typedef void (Harl::*fp)();
 * fp fp_arr[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
 *                 &Harl::undefined}; */
void Harl::complain(std::string level) {
  int idx;
  for (idx = 0; idx < LVLS - 1; idx++) {
    if (level == kLevels[idx]) {
      break;
    }
  }
  switch (idx) {
    case 0:
      (this->*fp[kDebug])();
    case 1:
      (this->*fp[kInfo])();
    case 2:
      (this->*fp[kWarning])();
    case 3:
      (this->*fp[kError])();
      break;
    default:
      (this->*fp[kUndefined])();
  }
}

void Harl::complain(const char *level) {
  if (!level) {
    std::cout << kComments[kUndefined] << std::endl;
  } else {
    complain(std::string(level));
  }
}

void Harl::debug() {
  std::cout << color::kYellow << "[ DEBUG ]" << color::kEnd << std::endl;
  std::cout << kComments[kDebug] << std::endl << std::endl;
}
void Harl::info() {
  std::cout << color::kYellow << "[ INFO ]" << color::kEnd << std::endl;
  std::cout << kComments[kInfo] << std::endl << std::endl;
}
void Harl::warning() {
  std::cout << color::kYellow << "[ WARNING ]" << color::kEnd << std::endl;
  std::cout << kComments[kWarning] << std::endl << std::endl;
}
void Harl::error() {
  std::cout << color::kYellow << "[ ERROR ]" << color::kEnd << std::endl;
  std::cout << kComments[kError] << std::endl << std::endl;
}
void Harl::undefined() { std::cout << kComments[kUndefined] << std::endl; }
