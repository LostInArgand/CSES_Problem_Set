//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <algorithm>


#define MOD 1000000007

typedef long long int ll;


using namespace std;


ll max(ll x, ll y){
    if (x > y){
        return x;
    }
    return y;
}

int min(int x, int y){
    if (x <= y){
        return x;
    }
    return y;
}

ll fastExpo(ll i, ll j, ll mod){
    ll res = 1;
    i = i % mod;
    if(j == 0){
        return 1;
    }
    if(i == 0){
        return 0;
    }
    while (j > 0){
        if((j & 1) == 1){
            res = (res * i) % mod;
        }
        j >>= 1;
        i = (i * i) % mod;
    }
    return res;
}

#define MAXN 200010

ll seg_tree[MAXN*4];

void build(int * arr, int i, int l, int r){
    if(l == r) seg_tree[i] = arr[l];
    else{
        int m = (l + r) / 2;
        build(arr, 2*i, l, m);
        build(arr, 2*i + 1, m + 1, r);
        seg_tree[i] = seg_tree[2*i] + seg_tree[2*i + 1];
    }
}

ll sum(int i, int segt_l, int segt_r, int l, int r){
    if(l > r) return 0;
    if(l == segt_l && r == segt_r) return seg_tree[i];
    int segt_m = (segt_l + segt_r) / 2;
    return sum(i*2, segt_l, segt_m, l, min(r, segt_m)) + sum(i*2 + 1, segt_m + 1, segt_r, max(l, segt_m + 1), r);
}

void update(int i, int segt_l, int segt_r, int ind, ll val){
    if (segt_l == segt_r) seg_tree[i] = val;
    else{
        int segt_m = (segt_l + segt_r) / 2;
        if(ind <= segt_m) update(i*2, segt_l, segt_m, ind, val);
        else update(i*2 + 1, segt_m + 1, segt_r, ind, val);
        seg_tree[i] = seg_tree[i * 2] + seg_tree[i * 2 + 1];
    }
}

int find_kth(int i, int segt_l, int segt_r, ll k){
    if(k > seg_tree[i]) return -1;
    if(segt_l == segt_r) return segt_l;
    int segt_m = (segt_l + segt_r) / 2;
    if(seg_tree[i * 2] >= k) return find_kth(i * 2, segt_l, segt_m, k);
    else return find_kth(i * 2 + 1, segt_m + 1, segt_r, k - seg_tree[i * 2]);
}

int main() {
//    freopen("/Users/pradithaalwis/Downloads/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(seg_tree, 0, sizeof(seg_tree));
    int n, k;
    cin >> n >> k;
    int arr[n];
    fill_n(arr, n, 1);
    build(arr, 1, 0, n - 1);
    ll curr_k = 0;
    int ind;
    for(int i = 0; i < n; i++){
        curr_k = (curr_k + k + 1);
        if(curr_k > seg_tree[1]){
            curr_k = (curr_k) % seg_tree[1];
            if(curr_k == 0) curr_k += seg_tree[1];
        }
        ind = find_kth(1, 0, n - 1, curr_k);
        cout << ind + 1 << ' ';//<< endl;
        curr_k--;
        update(1, 0, n - 1, ind, 0);
    }
    return 0;
}
