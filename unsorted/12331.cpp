#include <iostream>
#include <deque>

using namespace std;

deque<deque<int>> Line;
int last[3] = {-1, -1, -1};

int main() {
    string op;
    bool isPolice = false;
    while (cin >> op) {
        if (op == "POLICEWATCHING") 
            isPolice = true;
        else if (op == "DONUTSTIME")
            isPolice = false;
        else if (op == "ENQUEUE") {
            int id;
            cin >> id;
            if (!isPolice) {
                if (last[id%3] != -1)
                    Line[last[id%3]].push_back(id);
                else {
                    deque<int> newSeg;
                    newSeg.push_back(id);
                    last[id%3] = Line.size();
                    Line.push_back(newSeg);
                }
            } else {
                if (Line.size() != 0 && Line[Line.size()-1].front() % 3 == id % 3)
                    Line[Line.size()-1].push_back(id);
                else {
                    deque<int> newSeg;
                    newSeg.push_back(id);
                    last[id%3] = Line.size();
                    Line.push_back(newSeg);
                }
            }
        } else if (op == "DEQUEUE") {
            if (Line.size() != 0)
                continue;
            int res = Line.front().front();
            if (Line.front().size() == 1) {
                if (last[Line.front().front() % 3] == 0)
                    last[Line.front().front() % 3] = -1;
                for (int i = 0; i < 3; i++) {
                    if (last[i] != -1)
                        last[i]--;
                }
                Line.front().pop_front();
                Line.pop_front();
            } else 
                Line.front().pop_front();
            cout << res << "\n";
        }
    }
    return 0;
}