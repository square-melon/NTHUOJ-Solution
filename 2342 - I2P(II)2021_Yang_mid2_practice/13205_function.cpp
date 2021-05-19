#include "13205.h"

void Array::move(int d) {
    if (size == 0) return;
    if (cur + d <= 0) cur = 1;
    else if (cur + d > size) cur = size;
    else cur += d;
}

void Array::remove() {
    if (size == 0) return;
    for (int i = cur; i < size; i++) mem[i] = mem[i+1];
    size--;
    if (cur == size + 1) cur = size;
}

void List::move(int d) {
    if (d >= 0) 
        while (cur->getNxt() && d--) cur = cur->getNxt();
    else
        while (cur->getPre() && d++) cur = cur->getPre();
}

void List::remove() {
    if (cur) cur = cur->remove();
    size--;
}

ContainerBase* create(int n, int* arr, int q, Operation *op) {
    int op2 = 0, op3 = 0;
    for (int i = 0; i < q; i++) {
        if (op[i].type == 2) op2++;
        else if (op[i].type == 3) op3++;
    }
    ContainerBase *CB;
    if (op2 > op3) CB = new Array(n, arr);
    else CB = new List(n, arr);
    return CB;
}