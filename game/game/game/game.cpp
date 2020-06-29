//
//  game.cpp
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

//"♕ белая"
//"♛ черная"
#include "game.h"

game_t::game_t(const player_t &first, const player_t &second) :
    field() {
    players.push_back(first);
    players.push_back(second);
}

game_t::step_outcome_t game_t::apply_step(const step_t &step, size_t player_num) {
    
    if (step.xOfChip > 8 || step.xOfStep > 8 || step.yOfStep > 8 || step.yOfChip > 8) {
        return ERROR;
    }
    
    std::string &cellOfChip = field.fld[step.yOfChip - 1][step.xOfChip - 1];
    std::string &cellOfStep = field.fld[step.yOfStep - 1][step.xOfStep - 1];
    
    if (cellOfStep != "■") {
        return ERROR;
    }
    
    if (cellOfChip == "♕" || cellOfChip == "♛") {
        if (checkWay(step)) {
            clearWay(step, player_num);
            
            std::string curr = cellOfStep;
            cellOfStep = cellOfChip;
            cellOfChip = curr;
            
            if (checkDiagonals(step, player_num)) {
                return CONTINUES;
            }
            return FINISHED;
        } else {
            return ERROR;
        }
    }
    
    int dx = abs(step.xOfStep - step.xOfChip);
    int dy = abs(step.yOfStep - step.yOfChip);
    
    if (player_num == 0) {
        if (cellOfChip != "○") {
            return ERROR;
        }
        
        if (step.yOfStep >= step.yOfChip && (dy != 2 || dx != 2)) {
            return ERROR;
        }
    }
    
    if (player_num == 1) {
        if (cellOfChip != "●") {
            return ERROR;
        }
        
        if (step.yOfStep <= step.yOfChip) {
            return ERROR;
        }
        
    }
    
    if (dy > 2 || dx > 2) {
        return ERROR;
    } else if (dy == 2) {
        std::pair<int, int> coord = coordOfBitedChip(step);
        std::string &bitedChip = field.fld[coord.first - 1][coord.second - 1];
        
        if ((bitedChip == "●" || bitedChip == "♛") && player_num == 0) {
            bitedChip = "■";
        } else if ((bitedChip == "○" || bitedChip == "♕") && player_num == 1) {
            bitedChip = "■";
        } else {
            return ERROR;
        }
        
    }
    
    std::string curr = cellOfStep;
    cellOfStep = cellOfChip;
    cellOfChip = curr;
    
    if (player_num == 0 && step.yOfStep == 1) {
        cellOfStep = "♕";
    }
    
    if (player_num == 1 && step.yOfStep == 8) {
        cellOfStep = "♛";
    }
    
    if (checkAnotherStep(step, player_num)) {
        return CONTINUES;
    }
    
    return FINISHED;
}

bool game_t::checkWay(const step_t &step) {
    int dx = step.xOfStep - step.xOfChip;
    int dy = step.yOfStep - step.yOfChip;
    
    if (dx > 0 && dy > 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY >= step.yOfChip && currX >= step.xOfChip) {
            if (currY == step.yOfChip && currX == step.xOfChip) {
                return true;
            }
            --currX;
            --currY;
        }
    }
    
    if (dx > 0 && dy < 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY <= step.yOfChip && currX >= step.xOfChip) {
            if (currY == step.yOfChip && currX == step.xOfChip) {
                return true;
            }
            --currX;
            ++currY;
        }
    }
    
    if (dx < 0 && dy > 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY >= step.yOfChip && currX <= step.xOfChip) {
            if (currY == step.yOfChip && currX == step.xOfChip) {
                return true;
            }
            ++currX;
            --currY;
        }
    }
    
    if (dx < 0 && dy < 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY <= step.yOfChip && currX <= step.xOfChip) {
            if (currY == step.yOfChip && currX == step.xOfChip) {
                return true;
            }
            ++currX;
            ++currY;
        }
    }
    
    
    return false;
}

void game_t::clearWay(const step_t &step, size_t player_num) {
    int dx = step.xOfStep - step.xOfChip;
    int dy = step.yOfStep - step.yOfChip;
    
    if (dx > 0 && dy > 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY >= step.yOfChip && currX >= step.xOfChip) {
            if ((field.fld[currY - 1][currX - 1] == "●" || field.fld[currY - 1][currX - 1] == "♛") && player_num == 0) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            if ((field.fld[currY - 1][currX - 1] == "○" || field.fld[currY - 1][currX - 1] == "♕") && player_num == 1) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            --currX;
            --currY;
        }
    }
    
    if (dx > 0 && dy < 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY <= step.yOfChip && currX >= step.xOfChip) {
            if ((field.fld[currY - 1][currX - 1] == "●" || field.fld[currY - 1][currX - 1] == "♛") && player_num == 0) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            if ((field.fld[currY - 1][currX - 1] == "○" || field.fld[currY - 1][currX - 1] == "♕") && player_num == 1) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            --currX;
            ++currY;
        }
    }
    
    if (dx < 0 && dy > 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY >= step.yOfChip && currX <= step.xOfChip) {
            if ((field.fld[currY - 1][currX - 1] == "●" || field.fld[currY - 1][currX - 1] == "♛") && player_num == 0) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            if ((field.fld[currY - 1][currX - 1] == "○" || field.fld[currY - 1][currX - 1] == "♕") && player_num == 1) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            ++currX;
            --currY;
        }
    }
    
    if (dx < 0 && dy < 0) {
        int currX = step.xOfStep;
        int currY = step.yOfStep;
        while (currY <= step.yOfChip && currX <= step.xOfChip) {
            if ((field.fld[currY - 1][currX - 1] == "●" || field.fld[currY - 1][currX - 1] == "♛") && player_num == 0) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            if ((field.fld[currY - 1][currX - 1] == "○" || field.fld[currY - 1][currX - 1] == "♕") && player_num == 1) {
                field.fld[currY - 1][currX - 1] = "■";
            }
            ++currX;
            ++currY;
        }
    }
}

std::pair<int, int> game_t::coordOfBitedChip(const step_t &step) {
    //down right
    if (step.yOfChip - step.yOfStep < 0 && step.xOfChip - step.xOfStep < 0) {
        return std::make_pair(step.yOfChip + 1, step.xOfChip + 1);
    } else
    //down left
    if (step.yOfChip - step.yOfStep < 0 && step.xOfChip - step.xOfStep > 0) {
        return std::make_pair(step.yOfChip + 1, step.xOfChip - 1);
    } else
    //up right
    if (step.yOfChip - step.yOfStep > 0 && step.xOfChip - step.xOfStep < 0) {
        return std::make_pair(step.yOfChip - 1, step.xOfChip + 1);
    } else
    //up left
    {
        return std::make_pair(step.yOfChip - 1, step.xOfChip - 1);
    }
}

bool game_t::checkAnotherStep(const step_t &step, size_t player_num) {
    
    if (step.yOfStep - 3 > 0 && step.xOfStep - 3 > 0) {
        std::string upLeftPos = field.fld[step.yOfStep - 2][step.xOfStep - 2];
        std::string doubleUpLeftPos = field.fld[step.yOfStep - 3][step.xOfStep - 3];
        
        if (confirmAnotherStep(upLeftPos, doubleUpLeftPos, player_num)) {
            return true;
        }
    }
    
    if (step.yOfStep - 3 > 0 && step.xOfStep + 1 < 8) {
        std::string upRightPos = field.fld[step.yOfStep - 2][step.xOfStep];
        std::string doubleUpRightPos = field.fld[step.yOfStep - 3][step.xOfStep + 1];
        
        if (confirmAnotherStep(upRightPos, doubleUpRightPos, player_num)) {
            return true;
        }
    }
    
    if (step.yOfStep + 1 < 8 && step.xOfStep - 3 > 0) {
        std::string downLeftPos = field.fld[step.yOfStep][step.xOfStep - 2];
        std::string doubleDownLeftPos = field.fld[step.yOfStep + 1][step.xOfStep - 3];
        
        if (confirmAnotherStep(downLeftPos, doubleDownLeftPos, player_num)) {
            return true;
        }
    }
    
    if (step.yOfStep + 1 < 8 && step.xOfStep + 1 < 8) {
        std::string downRightPos = field.fld[step.yOfStep][step.xOfStep];
        std::string doubleDownRightPos = field.fld[step.yOfStep + 1][step.xOfStep + 1];
        
        if (confirmAnotherStep(downRightPos, doubleDownRightPos, player_num)) {
            return true;
        }
    }
    
    std::string currChip = field.fld[step.yOfStep - 1][step.xOfStep - 1];
    
    if (currChip == "♕" || currChip == "♛") {
        return checkDiagonals(step, player_num);
    }
    
    return false;
    
}

bool game_t::checkDiagonals(const step_t &step, size_t player_num) {
    
    int currX = step.xOfStep - 1;
    int currY = step.yOfStep - 1;
    
    // up left
    while (currX > 0 && currY > 0) {
        std::string pos = field.fld[currY][currX];
        std::string doublePos = field.fld[currY - 1][currX - 1];
        --currX;
        --currY;
        if (confirmAnotherStep(pos, doublePos, player_num)) {
            return true;
        }
    }
    
    currX = step.xOfStep - 1;
    currY = step.yOfStep - 1;
    
    // up right
    while (currX < 7 && currY > 0) {
        std::string pos = field.fld[currY][currX];
        std::string doublePos = field.fld[currY - 1][currX + 1];
        --currY;
        ++currX;
        if (confirmAnotherStep(pos, doublePos, player_num)) {
            return true;
        }
    }
    
    currX = step.xOfStep - 1;
    currY = step.yOfStep - 1;
    
    // down left
    while (currX > 0 && currY < 7) {
        std::string pos = field.fld[currY][currX];
        std::string doublePos = field.fld[currY + 1][currX - 1];
        ++currY;
        --currX;
        if (confirmAnotherStep(pos, doublePos, player_num)) {
            return true;
        }
    }
    
    currX = step.xOfStep - 1;
    currY = step.yOfStep - 1;
    
    // down right
    while (currX < 7 && currY < 7) {
        std::string pos = field.fld[currY][currX];
        std::string doublePos = field.fld[currY + 1][currX + 1];
        ++currY;
        ++currX;
        if (confirmAnotherStep(pos, doublePos, player_num)) {
            return true;
        }
    }
    
    return false;
}

bool game_t::confirmAnotherStep(std::string pos, std::string doublePos, size_t player_num) {
    if (((pos == "○" || pos == "♕") && player_num == 1) || ((pos == "●" || pos == "♛") && player_num == 0)) {
        if (doublePos == "■") {
            return true;
        }
    }
    return false;
}

game_t::game_outcome_t game_t::is_win() const {
    bool black = false;
    bool white = false;
    
    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 8; ++i) {
            if (field.fld[j][i] == "○") { white = true; }
            if (field.fld[j][i] == "●") { black = true; }
        }
    }
    
    if (!black || !white) {
        return WIN;
    }
    
    return IN_PROGRESS;
}

void game_t::play() {
    size_t counter = 1;
    while (is_win() == IN_PROGRESS) {
        
        counter = (counter + 1) % 2;
        step_outcome_t result = CONTINUES;
        while (result != FINISHED) {
            step_t step = players[counter]->make_step(field, counter);
            result = apply_step(step, counter);
            if (result == ERROR) {
                players[counter]->on_incorrect_step(step);
            }
        }
    }

    for (size_t i = 0; i < players.size(); ++i) {
        if (i == counter) {
            players[i]->on_win();
        } else {
            players[i]->on_lose();
        }
    }
}
