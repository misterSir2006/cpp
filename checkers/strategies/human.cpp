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
    
    std::cout << "  ";
    for (int i = 0; i < 8; i++) {
        std::cout << char(65 + i);
        std::cout << " ";
    }
    std::cout << std::endl;
    
    int i = 1;
  for (const auto &line : fld.fld) {
      std::cout << i << " ";
      i++;
      for (std::string c : line) {
          if (c == "○") {
              std::cout << "W";
          } else if (c == "●") {
              std::cout << "B";
          } else {
              std::cout << c;
          }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
    
  std::cout << "Player " << player_num << std::endl;
  std::cout << "Enter the coordinates of your chip, which you are going to make a move: " << std::endl;
    
    std::string chip;
  std::cin >> chip;
    if (chip.length() != 2) {
        return {20, 20, 20, 20};
    }
    int xOfChip = chip[0];
    int yOfChip = chip[1];
    
  std::cout << "Enter the coordinates where you want to move the chip: " << std::endl;
    
    std::string step;
  std::cin >> step;
    if (step.length() != 2) {
        return {20, 20, 20, 20};
    }
    int xOfStep = step[0];
    int yOfStep = step[1];
    
    return {int(xOfChip) - 64, int(yOfChip) - 48, int(xOfStep) - 64, int(yOfStep) - 48};
}

void human_strategy_t::on_incorrect_step(const step_t &step) const {
    std::cout << "--------------" << std::endl;
    std::cout << "Incorrect step" << std::endl;
    std::cout << "--------------" << std::endl;
}
