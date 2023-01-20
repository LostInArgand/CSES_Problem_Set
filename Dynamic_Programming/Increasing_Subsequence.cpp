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

int main(){
//    freopen("/Users/pradithaalwis/Downloads/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, inp;
    vector<int> dp;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> inp;
        auto itr = lower_bound(dp.begin(), dp.end(), inp);
        if(itr == dp.end()) dp.push_back(inp);
        else *itr = inp;
    }
    cout << dp.size() << endl;
    return 0;
}
