
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   void addFront(Tile* t);
   void addBack(Tile* t);
   void remove(int index);
   bool contains(Tile* t);
   Tile* get(int index);

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
