#include <iostream>
#include "10998.h"

using namespace std;

List_stack::List_stack() {
    head = new ListNode(0);
    tail = new ListNode(0);
    head->nextPtr = tail;
    head->prevPtr = NULL;
    tail->nextPtr = NULL;
    tail->prevPtr = head;
}

List_stack::~List_stack() {
    ListNode *cur = head;
    while (cur) {
        ListNode *todelete = cur;
        cur = cur->nextPtr;
        delete todelete;
    }
}

void List_stack::push(const int &n) {
    ListNode *newNode = new ListNode(n);
    newNode->prevPtr = tail->prevPtr;
    newNode->nextPtr = tail;
    newNode->prevPtr->nextPtr = newNode;
    tail->prevPtr = newNode;
}

void List_stack::pop() {
    if (tail->prevPtr == head) return;
    ListNode *todelete = tail->prevPtr;
    tail->prevPtr = tail->prevPtr->prevPtr;
    tail->prevPtr->nextPtr = tail;
    delete todelete;
}

void List_stack::print() {
    ListNode *cur = tail->prevPtr;
    int first = 0;
    while (cur != head) {
        if (first == 0)
            first = 1;
        else 
            cout << ' ';
        cout << cur->data;
        cur = cur->prevPtr;
    }
}