//
//  main.cpp
//  game
//
//  Created by Const. on 28.06.2020.
//  Copyright © 2020 Oleginc. All rights reserved.
//

#include <memory>

#include "game/game.h"
#include "strategies/human.h"
#include "strategies/computer.h"
#include <iostream>


int main() {

    std::cout << "Battle of smart and stupid strategy\n" << std::endl;
    auto player1 = std::make_shared<SmartComputerStrategy>("First player");
    auto player2 = std::make_shared<StupidComputerStrategy>("Second player");
  
    for (int i = 0; i < 1000; ++i) {
        game_t game(player1, player2);
        game.play();
    }

    player1->print_stat();
    player2->print_stat();
    
    std::cout << "Battle of two smart strategies\n" << std::endl;
      auto player3 = std::make_shared<SmartComputerStrategy>("First player");
      auto player4 = std::make_shared<SmartComputerStrategy>("Second player");
    
      for (int i = 0; i < 1000; ++i) {
          game_t game(player3, player4);
          game.play();
      }

      player3->print_stat();
      player4->print_stat();

    //uncomment it to test the human_strategy
//    auto player5 = std::make_shared<human_strategy_t>();
//    auto player6 = std::make_shared<SmartComputerStrategy>("First player");
//    game_t game(player5, player6);
//    game.play();

  return 0;
}
