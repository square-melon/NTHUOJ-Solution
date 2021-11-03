#include <iostream>
#include <string.h>

using namespace std;

class Matrix {
public:
    Matrix() {
        m = 0;
        n = 0;
    }

    Matrix(unsigned long long a, unsigned long long b) {
        m = a;
        n = b;
    }

    ~Matrix() {}

    unsigned long long m, n;
};

class Stack {
public:
    Stack() {
        top = 0;
    }
    ~Stack() {}

    void push(Matrix ma) {
        matrix[top].m = ma.m;
        matrix[top].n = ma.n;
        top++;
    }

    Matrix pop() {
        return matrix[--top];
    }

    void clear() {
        top = 0;
    }

    int cnt() {
        return top;
    }

    Matrix matrix[10000];
    int top;
};

int main() {
    Stack stack;
    int n;
    cin >> n;
    Matrix matrix[26];
    for (int i = 0; i < n; i++) {
        char name;
        unsigned long long n, m;
        cin >> name >> m >> n;
        matrix[name-'A'].m = m;
        matrix[name-'A'].n = n;
    }
    int t;
    cin >> t;
    while (t--) {
        stack.clear();
        unsigned long long int ans = 0;
        char cal[2005];
        cin >> cal;
        bool flag = true;
        for (int i = 0; i < strlen(cal); i++) {
            if (cal[i] == '(') {
                continue;
            } else if (cal[i] == ')') {
                Matrix b = stack.pop();
                Matrix a = stack.pop();
                if (a.n != b.m) {
                    flag = false;
                    break;
                } else {
                    Matrix newm(a.m, b.n);
                    ans += a.m * a.n * b.n;
                    stack.push(newm);
                }
            } else {
                stack.push(matrix[cal[i]-'A']);
            }
        }
        if (stack.cnt() == 2 && flag) {
            Matrix a = stack.pop();
            Matrix b = stack.pop();
            if (a.n != b.m) {
                flag = false;
                break;
            } else
                ans += a.m * a.n * b.n;
        }
        if (flag)
            cout << ans << "\n";
        else
            cout << "error\n";
    }
}