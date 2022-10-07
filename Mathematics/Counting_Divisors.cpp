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


vector<int> SieveOfEratosthenes(int n){
    bool prime[n + 1];
    vector<int> primes;
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);

    return primes;
}

int solve(int x, vector<int> primes){
    if(x == 1) return 1;
    int ans = 1, count = 0;
    vector<int> :: iterator itr;
    itr = primes.begin();
    while((*itr) * (*itr) <= x){
        count = 0;
        while(x % (*itr) == 0){
            count++;
            x /= (*itr);
        }
        ans *= count + 1;
        ++itr;
    }
    if(x != 1) ans *= 2;
    return ans;
}


int main() {
//    freopen("/Users/pradithaalwis/CLionProjects/csesPractice/test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, ans;
    cin >> n;
    vector<int> primes = SieveOfEratosthenes(1010);
    for(int i = 0; i < n; i++){
        cin >> x;
        ans = solve(x, primes);
        cout << ans << endl;
    }
    return 0;
}
