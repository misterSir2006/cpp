//
//  structures.h
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#pragma once

#include <algorithm>
#include <string>

struct step_t {
  step_t(int xOfChip, int yOfChip, int xOfStep, int yOfStep) :
    xOfChip{xOfChip},
    yOfChip{yOfChip},
    xOfStep{xOfStep},
    yOfStep{yOfStep}{}
    
  int xOfChip, yOfChip;
  int xOfStep, yOfStep;
};

struct field_t {
    field_t() {
        
        // fill desk
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (i % 2 != 0) {
                    if (j % 2 != 0) {
                        fld[i][j] = "□";
                    } else {
                        fld[i][j] = "■";
                    }
                } else {
                    if (j % 2 != 0) {
                        fld[i][j] = "■";
                    } else {
                        fld[i][j] = "□";
                    }
                }
                
            }
        }
        
        // fill black player
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (fld[i][j] == "■") {
                    fld[i][j] = "●";
                }
            }
        }
        
        // fill white player
        for (int i = 5; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (fld[i][j] == "■") {
                    fld[i][j] = "○";
                }
            }
        }
        
    }

    std::string fld[8][8];
};
