
#include "LinkedList.h"

#include<iostream>

LinkedList::LinkedList() {
   head = nullptr;
}

LinkedList::~LinkedList() {
  Node* n = head;
  Node* temp = nullptr;
  while (n != nullptr){
    temp = n->next;
    delete n;
    n = temp;
  }
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

void LinkedList::removeFirst(){
  if(head == nullptr){
    std::cout << "Empty List" << std::endl;
  } else {
    Node* n = head;
    head = head->next;
    delete n;
  }
}

void LinkedList::removeLast(){
  Node* n = nullptr;
  Node* prev = nullptr;
  n = head;
  while (n->next != nullptr){
    prev = n;
    n = n->next;
  }
  prev->next = nullptr;
  delete n;
}
