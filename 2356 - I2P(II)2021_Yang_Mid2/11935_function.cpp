#include "11935.h"

void _stack::push(const _node N) {
    _node *newNode = new _node(N.data);
    newNode->prev = End->prev;
    newNode->next = End;
    End->prev->next = newNode;
    End->prev = newNode;
}

void _stack::pop() {
    if (End->prev == Begin) return;
    _node *todelete = End->prev;
    End->prev = End->prev->prev;
    End->prev->next = End;
    delete todelete;
}

_node* _stack::get_data() {
    if (End->prev == Begin) return nullptr;
    return End->prev;
}

void _queue::push(const _node N) {
    _node *newNode = new _node(N.data);
    newNode->prev = End->prev;
    newNode->next = End;
    End->prev->next = newNode;
    End->prev = newNode;
}

void _queue::pop() {
    if (Begin->next == End) return;
    _node *todelete = Begin->next;
    Begin->next = Begin->next->next;
    Begin->next->prev = Begin;
    delete todelete;
}

_node* _queue::get_data() {
    if (Begin->next == End) return nullptr;
    return Begin->next;
}