#include <iostream>
#include "13178.h"

Node::~Node() {
    Node *cur;
    if (neighbors[0] != nullptr) cur = neighbors[0];
    else cur = neighbors[1];
    if (cur)
        cur->unLink(this);
    delete cur;
}

List::~List() {
    if (head != nullptr)
        delete head;
}

void List::init(std::string s) {
    head = new Node(s[0]);
    Node *cur = head;
    for (int i = 1; i < s.size(); i++) {
        Node *newNode = new Node(s[i]);
        cur->link(newNode);
        newNode->link(cur);
        cur = newNode;
    }
    tail = cur;
}

void List::merge(List &front, List &back) {
    if (front.head == nullptr) {
        head = back.head;
        tail = back.tail;
    } else if (back.head == nullptr) {
        head = front.head;
        tail = front.tail;
    } else {
        front.tail->link(back.head);
        back.head->link(front.tail);
        head = front.head;
        tail = back.tail;
    }
}

void List::swap(List &swapList) {
    Node *tmp = head;
    head = swapList.head;
    swapList.head = tmp;
    Node *tmp2 = tail;
    tail = swapList.tail;
    swapList.tail = tmp2;
}

void List::reverse() {
    Node *tmp = head;
    head = tail;
    tail = tmp;
}