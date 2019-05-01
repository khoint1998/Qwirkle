
#include "LinkedList.h"
#include "Player.h"
#include "GameEngine.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   GameEngine* game = new GameEngine();
   Player* a = new Player(1,"Khoi");
   game->addPlayer(a);
   Tile* t = new Tile('B',4);
   a->getPlayerHand()->addBack(t);
   game->printState(a);
   game->saveGame("a.txt",a);
   delete a;
   delete game;
   return EXIT_SUCCESS;
}
