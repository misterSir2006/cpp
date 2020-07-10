//
//  computer.cpp
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#include "computer.h"

#include <cassert>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sys/time.h>


StupidComputerStrategy::StupidComputerStrategy(std::string name) :
  name(std::move(name)) {}

step_t StupidComputerStrategy::make_step(const field_t &fld, size_t player_num) {
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
    
    struct timeval tv;
    gettimeofday(&tv,NULL);
    srand((uint)tv.tv_sec * 1000 + tv.tv_usec / 1000);
      
    int randChip = rand() % chips.size();
    std::pair<int, int> chip = chips[randChip];
    
    
    step_t currMove = check(fld, chip, player_num);
    
    while (currMove.xOfChip == -1) {
        int randNumber1 = rand() % chips.size();
        chip = chips[randNumber1];
        if (fld.fld[chip.first][chip.second] == "♕" || fld.fld[chip.first][chip.second] == "♛") {
            break;
        }
        currMove = check(fld, chip, player_num);
    }
    
    if (currMove.xOfChip != -1) {
        return currMove;
    }
    
    
    std::vector<std::pair<int, int>> moves;
    
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (fld.fld[i][j] == "■") {
                moves.emplace_back(i, j);
            }
        }
    }
    
    int randNumber2 = rand() % moves.size();
    std::pair<int, int> move = moves[randNumber2];
    
    return {chip.second + 1, chip.first + 1, move.second + 1, move.first + 1};
}

step_t StupidComputerStrategy::check(const field_t &fld, std::pair<int, int> chip, size_t player_num) {
    
        // up left
        if (chip.first - 1 >= 0 && chip.second - 1 >= 0) {
            if (fld.fld[chip.first - 1][chip.second - 1] == "■") {
                if (player_num == 0) {
                    return {chip.second + 1, chip.first + 1, chip.second, chip.first};
                }
            }
        }
        
        // up right
        if (chip.first - 1 >= 0 && chip.second + 1 < 8) {
            if (fld.fld[chip.first - 1][chip.second + 1] == "■") {
                if (player_num == 0) {
                    return {chip.second + 1, chip.first + 1, chip.second + 2, chip.first};
                }
            }
        }
        
        // down left
        if (chip.first + 1 < 8 && chip.second - 1 >= 0) {
            if (fld.fld[chip.first + 1][chip.second - 1] == "■") {
                if (player_num == 1) {
                    return {chip.second + 1, chip.first + 1, chip.second, chip.first + 2};
                }
            }
        }
        
        
        // down right
        if (chip.first + 1 < 8 && chip.second + 1 < 8) {
            if (fld.fld[chip.first + 1][chip.second + 1] == "■") {
                if (player_num == 1) {
                    return {chip.second + 1, chip.first + 1, chip.second + 2, chip.first + 2};
                }
            }
        }
    
    if (chip.first - 2 >= 0 && chip.second - 2 >= 0) {
        if (fld.fld[chip.first - 2][chip.second - 2] == "■") {
            if (player_num == 0) {
                if (fld.fld[chip.first - 1][chip.second - 1] == "●") {
                    return {chip.second + 1, chip.first + 1, chip.second - 1, chip.first - 1};
                }
            } else {
                if (fld.fld[chip.first - 1][chip.second - 1] == "○") {
                    return {chip.second + 1, chip.first + 1, chip.second - 1, chip.first - 1};
                }
            }
        }
    }
    
    //double up right
    if (chip.first - 2 >= 0 && chip.second + 2 < 8) {
        if (fld.fld[chip.first - 2][chip.second + 2] == "■") {
            if (player_num == 0) {
                if (fld.fld[chip.first - 1][chip.second + 1] == "●") {
                    return {chip.second + 1, chip.first + 1, chip.second + 3, chip.first - 1};
                }
            } else {
                if (fld.fld[chip.first - 1][chip.second + 1] == "○") {
                    return {chip.second + 1, chip.first + 1, chip.second + 3, chip.first - 1};
                }
            }
        }
    }
    
    //double down left
    if (chip.first + 2 < 8 && chip.second - 2 >= 0) {
        if (fld.fld[chip.first + 2][chip.second - 2] == "■") {
            if (player_num == 0) {
                if (fld.fld[chip.first + 1][chip.second - 1] == "●") {
                    return {chip.second + 1, chip.first + 1, chip.second - 1, chip.first + 3};
                }
            } else {
                if (fld.fld[chip.first + 1][chip.second - 1] == "○") {
                    return {chip.second + 1, chip.first + 1, chip.second - 1, chip.first + 3};
                }
            }
        }
    }
    
    //double down right
    if (chip.first + 2 < 8 && chip.second + 2 < 8) {
        if (fld.fld[chip.first + 2][chip.second + 2] == "■") {
            if (player_num == 0) {
                if (fld.fld[chip.first + 1][chip.second + 1] == "●") {
                    return {chip.second + 1, chip.first + 1, chip.second + 3, chip.first + 3};
                }
            } else {
                if (fld.fld[chip.first + 1][chip.second + 1] == "○") {
                    return {chip.second + 1, chip.first + 1, chip.second + 3, chip.first + 3};
                }
            }
        }
    }
    
    return {-1, -1, -1, -1};
}

void StupidComputerStrategy::print_stat() const {
  std::cout << "Stupid model [" << name << "]: " << std::endl;
  computer_interface_t::print_stat();
}
