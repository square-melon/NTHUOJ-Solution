#include <iostream>
#include <queue>

using namespace std;

int line[3] = {-1, -1, -1};
queue<int> people[3]; // 0 for American 1 for Africa 2 for Japanese

void enqueue(int);
int dequeue();

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "ENQUEUE") {
            int num;
            cin >> num;
            enqueue(num);
        } else if (op == "DEQUEUE")
            cout << dequeue() << '\n';
    }
    return 0;
}

void enqueue(int num) {
    people[num % 3].push(num);
    int flag = -1;
    for (int i = 0; i < 3; i++) {
        if (line[i] == num % 3)
            break;
        else if (line[i] == -1) {
            flag = i;
            break;
        }
    }
    if (flag != -1)
        line[flag] = num % 3;
}

int dequeue() {
    int res = people[line[0]].front();
    people[line[0]].pop();
    if (people[line[0]].empty()) {
        line[0] = line[1];
        line[1] = line[2];
        line[2] = -1;
    }
    return res;
}