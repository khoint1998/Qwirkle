
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
}

LinkedList::~LinkedList() {

}

void LinkedList::addFront(Tile* t){
  Node* n = new Node(t,nullptr);
  if(head != nullptr){
    n->next = head;
    head = n;
  } else {
    head = n;
  }
}

void LinkedList::addBack(Tile*t){
  Node* n = new Node(t,nullptr);
  if(head == nullptr){
    head = n;
  } else {
    Node *tail = head;
    while (tail->next != nullptr){
      tail = tail->next;
    }
    tail->next = n;
  }
}

Tile* LinkedList::get(int index){
  Node *indexPtr = head;
  for(int i = 0; i <= index; i++){
    indexPtr = indexPtr->next;
  }
  return indexPtr->tile;
}

bool LinkedList::contains(Tile* t){
  bool found = false;
  Node *node = head;

  while(node != nullptr && !found){
    if(node->tile->compareTile(t)){
      found = true;
    }
    node = node->next;
  }
  return found;
}

void LinkedList::remove(int index){

}
