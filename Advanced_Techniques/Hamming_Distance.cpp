#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>

#define MOD 1000000007

typedef long long int ll;


using namespace std;


int max(int x, int y){
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    string inp;
    int num;
    for(int i=0; i < n; i++){
        cin >> inp;
        num = stoi(inp, nullptr, 2);
        arr.push_back(num);
    }
    int ans = 30;
    for(int i=0; i < n; i++){
        for(int j= i + 1; j < n; j++){
            ans = min(ans, __builtin_popcount(arr[i]^arr[j]));
        }
    }
    cout << ans << endl;
    return 0;
}
