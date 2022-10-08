#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>

typedef long long int ll;


using namespace std;

long long int fact[1000001];

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

long long int modInverse(long long int val, long long int mod){
    return fastExpo(val, mod - 2, mod);
}

long long int ncr(long long int n, long long int r){
    long long int mod = 1000000007;
    if(n < r) return 0;
    if(r == 0) return 1;

    long long int ans = (((fact[n] * modInverse(fact[r], mod)) % mod) * modInverse(fact[n - r], mod)) % mod;
    return ans;
}


int main() {
//    freopen("/Users/pradithaalwis/CLionProjects/csesPractice/test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        fact[i] = (fact[i - 1] * i) % 1000000007;
    }
    long long int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        long long int ans = ncr(a, b);
        cout << ans << '\n';
    }
    return 0;
}
