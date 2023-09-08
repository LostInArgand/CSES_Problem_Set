#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

#define MAXN 200010

typedef long long ll;

using namespace std;

void build(ll * seg_tree, vector<int> & arr, int v, int seg_l, int seg_r){
    if (seg_l == seg_r){
        seg_tree[v] = arr[seg_l];
    }
    else{
        int seg_m = (seg_l + seg_r) / 2;
        build(seg_tree, arr, 2 * v, seg_l, seg_m);
        build(seg_tree, arr, 2 * v + 1, seg_m + 1, seg_r);
        seg_tree[v] = 0;
//        seg_tree[v] = seg_tree[2 * v] + seg_tree[2 * v + 1];
    }
}

void update(ll * seg_tree, int v, int seg_l, int seg_r, int l, int r, ll add){
    if (l > r) return;
    if (seg_l == l && seg_r == r) seg_tree[v] += add;
    else{
        int seg_m = (seg_l + seg_r) / 2;
        update(seg_tree, 2 * v, seg_l, seg_m, l, min(r, seg_m), add);
        update(seg_tree, 2 * v + 1, seg_m + 1, seg_r, max(l, seg_m + 1), r, add);
    }
}

ll get(ll * seg_tree, int v, int seg_l, int seg_r, int pos){
    if (seg_l == seg_r) return seg_tree[v];
    int seg_m = (seg_l + seg_r) / 2;
    if (pos <= seg_m) return seg_tree[v] + get(seg_tree, 2 * v, seg_l, seg_m, pos);
    else return seg_tree[v] + get(seg_tree, 2 * v + 1, seg_m + 1, seg_r, pos);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q, inp;
    cin >> n >> q;
    vector<int> arr;
    ll seg_tree[4 * (n + 10)];
    for(int i = 0; i < n; i++){
        cin >> inp;
        arr.push_back(inp);
    }
    build(seg_tree, arr, 1, 0, n - 1);
    int op, a, b, add;
    for(int j = 0; j < q; j++){
        cin >> op;
        if (op == 1){
            cin >> a >> b >> add;
            update(seg_tree, 1, 0, n - 1, a - 1, b - 1, add);
        }
        else{
            cin >> a;
            cout << get(seg_tree, 1, 0, n - 1, a - 1) << endl;
        }
    }
    return 0;
}
