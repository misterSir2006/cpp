//
//  computer.h
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#pragma once

#include <string>

#include "../game/structures.h"
#include "computer_interface.h"

class StupidComputerStrategy : public computer_interface_t {
public:
  explicit StupidComputerStrategy(std::string name);
  step_t make_step(const field_t &field, size_t player_num) override;

  void print_stat() const override;

private:
    step_t check(const field_t &fld, std::pair<int, int> chip, size_t player_num);
  std::string name;
};


class SmartComputerStrategy : public computer_interface_t {
public:
  explicit SmartComputerStrategy(std::string name);
  step_t make_step(const field_t &field, size_t player_num) override;

  void print_stat() const override;

private:
    step_t checkKill(const field_t &fld, size_t player_num);
    step_t check(const field_t &fld, std::pair<int, int> chip, size_t player_num);
  std::string name;
};
