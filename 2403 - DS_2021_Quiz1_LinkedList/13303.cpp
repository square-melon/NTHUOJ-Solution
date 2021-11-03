#include <iostream>

using namespace std;

unsigned long long int cur_people;

class Node {
public:
    Node(unsigned long long int n) {
        data = n;
        next = NULL;
    }

    ~Node() {}

    Node *next;
    unsigned long long int data;
};

class LinkedList {
public:
    LinkedList() {}
    ~LinkedList() {}

    void addNode(unsigned long long int n) {
        if (!head) {
            head = new Node(n);
            head->next = head;
            tail = head;
        } else {
            Node *newNode = new Node(n);
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void passBomb(unsigned long long int n) {
        if (cur_people == 1)
            return;
        n %= cur_people;
        while (n--) {
            prev_bomb_taker = bomb_taker;
            bomb_taker = bomb_taker->next;
        }
        Node *tmp = bomb_taker;
        bomb_taker = bomb_taker->next;
        if (cur_people > 2)
            prev_bomb_taker->next = bomb_taker;
        else
            bomb_taker->next = bomb_taker;
        delete(tmp);
        cur_people--;
    }

    void join(unsigned long long int n) {
        Node *newNode = new Node(n);
        newNode->next = bomb_taker->next;
        bomb_taker->next = newNode;
        if (cur_people == 1)
            prev_bomb_taker = newNode;
        cur_people++;
    }

    void print() {
        Node *cur = bomb_taker;
        cout << cur->data;
        cur = cur->next;
        while (cur != bomb_taker) {
            cout << " " << cur->data;
            cur = cur->next;
        }
        cout << "\n";
    }

    Node *head;
    Node *tail;
    Node *bomb_taker;
    Node *prev_bomb_taker;
};

LinkedList linkedList;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long int N;
    cin >> N;
    for (unsigned long long int i = 0; i < N; i++) {
        unsigned long long int tmp;
        cin >> tmp;
        linkedList.addNode(tmp);
    }
    cur_people = N;
    linkedList.bomb_taker = linkedList.head;
    linkedList.prev_bomb_taker = linkedList.tail;
    unsigned long long int a, b;
    cin >> a >> b;
    while (a != -1 || b != -1) {
        if (a == 1)
            linkedList.passBomb(b);
        else if (a == 2)
            linkedList.join(b);
        cin >> a >> b;
    }
    linkedList.print();
}