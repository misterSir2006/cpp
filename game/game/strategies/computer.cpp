//
//  computer.cpp
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#include "computer.h"

#include <cassert>
#include <iostream>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sys/time.h>


computer_strategy_t::computer_strategy_t(std::string name) :
  name(std::move(name)) {}

step_t computer_strategy_t::make_step(const field_t &fld, size_t player_num) {
  std::vector<std::pair<int, int>> chips;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
        if (player_num == 0) {
            if (fld.fld[i][j] == "○" || fld.fld[i][j] == "♕") {
              chips.emplace_back(i, j);
            }
        } else {
            if (fld.fld[i][j] == "●" || fld.fld[i][j] == "♛") {
              chips.emplace_back(i, j);
            }
        }
      
    }
  }
    
  std::vector<std::pair<int, int>> moves;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
        if (fld.fld[i][j] == "■") {
          moves.emplace_back(i, j);
        }
    }
  }
  struct timeval tv;
  gettimeofday(&tv,NULL);
  srand((uint)tv.tv_sec * 1000 + tv.tv_usec / 1000);
  int randNumber1 = rand() % chips.size();
  std::pair<int, int> chip = chips[randNumber1];
  int randNumber2 = rand() % moves.size();
    
  std::pair<int, int> move = moves[randNumber2];
  return {chip.second + 1, chip.first + 1, move.second + 1, move.first + 1};
}

void computer_strategy_t::print_stat() const {
  std::cout << "Random model [" << name << "]: " << std::endl;
  computer_interface_t::print_stat();
}
