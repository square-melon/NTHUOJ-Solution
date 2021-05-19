#include "12224.h"
#include <iostream>
#include <stdexcept>

void List::InsertHead(int data) {
    ListNode *node = new ListNode(data);
    if (head == nullptr) {
        head = node;
        tail = node;
        middle = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    cnt++;
    pos++;
    while (cnt / 2 + 1 < pos) {
        middle = middle->prev;
        pos--;
    }
}

int List::RemoveHead() {
    if (head) {
        ListNode *todelete = head;
        head = head->next;
        int val = todelete->data;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete todelete;
        cnt--;
        pos--;
        while (cnt / 2 + 1 > pos && cnt != 0) {
            middle = middle->next;
            pos++;
        }
        return val;
    } else 
        throw std::out_of_range("\n");
}

void List::InsertTail(int data) {
    ListNode *node = new ListNode(data);
    if (head == nullptr) {
        head = node;
        tail = node;
        middle = node;
        pos = 1;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    cnt++;
    while (cnt / 2 + 1 > pos) {
        middle = middle->next;
        pos++;
    }
}

int List::RemoveTail() {
    if (head) {
        ListNode *todelete = tail;
        tail = tail->prev;
        int val = todelete->data;
        if (tail) tail->next = nullptr;
        else head = nullptr; 
        delete todelete;
        cnt--;
        while (cnt / 2 + 1 < pos && cnt != 0) {
            middle = middle->prev;
            pos--;
        }
        if (cnt == 0) pos = 0;
        return val;
    } else throw std::out_of_range("\n");
}

void List::Swap() {
    if (cnt <= 1) return;
    ListNode *newHead = middle, *newTail = middle->prev, *newMiddle = head;
    tail->next = head;
    head->prev = tail;
    head = newHead;
    tail = newTail;
    middle = newMiddle;
    if (cnt % 2) middle = middle->prev;
    head->prev = nullptr;
    tail->next = nullptr;
}

int List::getSize() {
    return cnt;
}

int List::getMiddle() {
    return pos;
}