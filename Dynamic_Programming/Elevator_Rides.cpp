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
#include <stack>
#include <algorithm>


#define MOD 1000000007

typedef long long ll;


using namespace std;


ll max(ll x, ll y){
    if (x > y){
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

int solve(int n, int x, int * w){
    pair<int, int> best[1<<n];
    best[0] = {1, 0};
    for(int subset = 1; subset < (1 << n); subset++){
        best[subset] = {n + 1, 0};
        for(int i = 0; i < n; i++){
            if(subset & (1 << i)) {
                pair<int, int> temp = best[subset ^ (1 << i)];
                if (temp.second + w[i] <= x) temp.second += w[i];
                else temp = {temp.first+1, w[i]};
                best[subset] = min(best[subset], temp);
            }
        }
    }
    return best[(1 << n) - 1].first;
}

int main(){
//    freopen("/Users/pradithaalwis/Downloads/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int weights[n];
    for(int i=0; i < n; i++){
        cin >> weights[i];
    }
    cout << solve(n, x, weights) << endl;
    return 0;
}
