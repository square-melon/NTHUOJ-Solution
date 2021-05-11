#include "11417.h"
#include <string.h>

Str::Str(char *str) {
    head = new Char(str[0]);
    Char *cur = head;
    for (int i = 1; i < strlen(str); i++) {
        cur->next = new Char(str[i]);
        cur = cur->next;
    }
    tail = cur;
}

Str::Str(const Str &str) {
    Char *cur = str.head;
    head = new Char(cur->text);
    Char *curr = head;
    while (cur->next) {
        cur = cur->next;
        curr = curr->next = new Char(cur->text);
    }
    tail = curr;
}

Str& Str::strInsert(const Str &str) {
    Char *cur = tail;
    Char *curr = str.head;
    while (curr) {
        cur = cur->next = new Char(curr->text);
        curr = curr->next;
    }
    tail = cur;
    return *this;
}