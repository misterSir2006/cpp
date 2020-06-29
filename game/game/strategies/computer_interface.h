//
//  computer_interface.h
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#pragma once

#include "interface.h"

class computer_interface_t : public strategy_interface_t {
public:
  computer_interface_t();

  void on_win() override;
  void on_lose() override;

  void on_incorrect_step(const step_t &step) const override;

  virtual void print_stat() const;

private:
  size_t win_counter;
  size_t lose_counter;
};
