//
//  game.h
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include "../strategies/interface.h"
#include "structures.h"

class game_t {
public:
    using player_t = std::shared_ptr<strategy_interface_t>;
    game_t(const player_t &first, const player_t &second);

    void play();
    
    enum step_outcome_t {
        FINISHED,
        CONTINUES,
        ERROR,
        TIE
    };
 

private:
    enum game_outcome_t {
        WIN,
        IN_PROGRESS
    };

    game_outcome_t is_win() const;
    
    step_outcome_t apply_step(const step_t &step, size_t player_num);
    std::pair<int, int> coordOfBitedChip(const step_t &step);
    
    bool confirmAnotherStep(std::string pos, std::string doublePos, size_t player_num);
    bool checkDiagonals(const step_t &step, size_t player_num);
    bool checkWay(const step_t &step);
    bool checkTie(size_t player_num);
    
    void clearWay(const step_t &step, size_t player_num);
    
    field_t field;
    std::vector<player_t> players;
};
