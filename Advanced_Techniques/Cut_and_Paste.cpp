#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <list>
#include <cstring>
#include <queue>
#include <map>

typedef long long ll;

using namespace std;

struct Node{
    char val;
    int weight, size;
    Node *left, *right;
    explicit Node(char c) : val(c), weight(rand()), size(1), left(nullptr), right(nullptr) {}
} *root;

inline int size(Node *treap) {return treap ? treap->size : 0;}

void split(Node *treap, Node *&left, Node *&right, int x){
    if(!treap){
        left = right = nullptr;
        return;
    }
    if(size(treap->left) < x){
        split(treap->right, treap->right, right, x - size(treap->left) - 1);
        left = treap;
    }
    else{
        split(treap->left, left, treap->left, x);
        right = treap;
    }
    treap->size = 1 + size(treap->left) + size(treap->right);
}

void merge(Node *&treap, Node *left, Node *right){
    if(left == nullptr){
        treap = right;
        return;
    }
    if(right == nullptr){
        treap = left;
        return;
    }
    if(left->weight < right->weight){
        merge(left->right, left->right, right);
        treap = left;
    }
    else{
        merge(right->left, left, right->left);
        treap = right;
    }
    treap->size = 1 + size(treap->left) + size(treap->right);
}

ostream &operator<<(ostream &os, Node *node){
    if(!node) return os;
    os << node->left;
    os << node->val;
    os << node->right;
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l, r;
    string S;
    cin >> n >> m >> S;
    for(char c : S){
        merge(root, root, new Node(c));
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        Node *a, *b, *c, *d;
        split(root, a, b, l - 1);
        split(b, c, d, r - l + 1);
        merge(root, a, d);
        merge(root, root, c);
    }
    cout << root << endl;
    return 0;
}
