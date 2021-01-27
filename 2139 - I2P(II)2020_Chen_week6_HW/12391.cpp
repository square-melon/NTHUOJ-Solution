#include <iostream>

using namespace std;

class Node {
    public:
        int term;
        int val;
        Node* l;
        Node* r;
        Node() {val = 0, l = NULL, r = NULL;}
        ~Node(){}
};

int* arr;

Node* construct(int l, int r) {
    int mid = (l + r) / 2;
    Node* newNode = new Node;
    newNode->val = arr[mid];
    newNode->term = mid;
    if (mid - 1 >= l) newNode->l = construct(l, mid - 1);
    if (mid + 1 <= r) newNode->r = construct(mid + 1, r);
    return newNode;
}

int search(Node* node, int x) {
    if (x == node->val) return node->term + 1;
    else if (x < node->val) {
        if (!node->l) return -1;
        else return search(node->l, x);
    }else {
        if (!node->r) return -1;
        else return search(node->r, x);
    }
}

void freeBST(Node* BST) {
    if (BST->l) freeBST(BST->l);
    if (BST->r) freeBST(BST->r);
    delete BST;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    while(cin >> n >> q) {
        arr = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Node* BST = construct(0, n - 1);
        while (q--) {
            int f;
            cin >> f;
            if (search(BST, f) == -1) cout << "Break your bridge!\n";
            else cout << search(BST, f) << '\n';
        }
        delete[] arr;
        freeBST(BST);
    }
    
}