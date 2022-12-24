//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>


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

int main() {
//    freopen("/Users/pradithaalwis/Downloads/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n, inp;
    cin >> x >> n;
    set<pair<int, int>> street;
    street.insert(make_pair(0, -1));
    street.insert(make_pair(x, n));
    vector<int> lights;
    for(int i=0; i < n; i++){
        cin >> inp;
        street.insert(make_pair(inp, i));
        lights.push_back(inp);
    }
    set<pair<int, int>> :: iterator itr;
    int prev = 0;
    int maxx = 0;
    for(itr = street.begin(); itr != street.end(); ++itr){
        maxx = max(itr->first - prev, maxx);
        prev = itr->first;
    }

    maxx = max(x - prev, maxx);
    vector<int> ans;
    ans.push_back(maxx);
    int post = 0;
    for(int i = n - 1; i > 0; --i){
        itr = street.find(make_pair(lights[i], i));
        prev = (--itr)->first;
        itr++;
        post = (++itr)->first;
        --itr;
        street.erase(itr);
        maxx = max(maxx, post - prev);
        ans.push_back(maxx);
    }
    vector<int> :: reverse_iterator ritr;
    for(ritr = ans.rbegin(); ritr != ans.rend(); ++ritr){
        cout << *ritr << ' ';
    }
    return 0;
}
