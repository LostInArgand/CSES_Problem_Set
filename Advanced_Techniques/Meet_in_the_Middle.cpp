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

unordered_map<ll, ll> mem;
ll ans = 0;

void calculate_subsets(const ll *arr, int n, int start, bool mem_type, ll x){
    mem[0] = 1;
    for(int i=0; i < (1 << n); i++){
        ll sum = 0L;
        for(int j=0; j < n; j++){
            if(i & (1<<j)) sum += arr[start + j];
        }
        if(sum == 0) continue;
        if(mem_type){
            if(mem.count(x - sum)) ans += mem[x - sum];
        }
        else{
            if(mem.count(sum) == 0) mem[sum] = 0L;
            mem[sum]++;
        }
    }
}

void solve(const ll *arr, int n, ll x){
    calculate_subsets(arr, n/2, 0, false, x);
    calculate_subsets(arr, n - (n / 2), n/2, true, x);

    unordered_map<ll, ll> :: iterator itr;
    if(mem.count(x)) ans += mem[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    solve(arr, n, x);
    cout << ans << endl;

    return 0;
}
