//
//  interface.h
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#pragma once

#include "../game/structures.h"

class strategy_interface_t {
public:
  virtual step_t make_step(const field_t &field, size_t player_num) = 0;
  virtual void on_incorrect_step(const step_t &step) const = 0;

  virtual void on_lose() = 0;
  virtual void on_win() = 0;
    virtual void on_tie() = 0;
};
