//
//  human.cpp
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#include "human.h"

#include <iostream>

void human_strategy_t::on_win() {
  std::cout << "You win!" << std::endl;
}
void human_strategy_t::on_lose() {
  std::cout << "You lose!" << std::endl;
}
void human_strategy_t::on_tie() {
  std::cout << "Tie!" << std::endl;
}

step_t human_strategy_t::make_step(const field_t &fld, size_t player_num) {
  std::cout << "Field:" << std::endl;
  for (const auto &line : fld.fld) {
    for (std::string c : line) {
      std::cout << c;
    }
    std::cout << std::endl;
  }
    
  std::cout << "Player " << player_num << std::endl;
  std::cout << "Enter the coordinates of your chip, which you are going to make a move: " << std::endl;
  int xOfChip, yOfChip;
  std::cin >> xOfChip >> yOfChip;
    
  std::cout << "Enter the coordinates where you want to move the chip: " << std::endl;
  int xOfStep, yOfStep;
  std::cin >> xOfStep >> yOfStep;
    
  return {xOfChip, 9 - yOfChip, xOfStep, 9 - yOfStep};
}

void human_strategy_t::on_incorrect_step(const step_t &step) const {
    std::cout << "--------------" << std::endl;
    std::cout << "Incorrect step" << std::endl;
    std::cout << "--------------" << std::endl;
}
