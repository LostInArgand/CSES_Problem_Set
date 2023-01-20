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

int solve(int n){
    int sum = n * (n + 1);
    sum /= 2;
    if(sum % 2) return 0;
    sum /= 2;
    int dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= sum; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(i <= j) dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= 1000000007;
        }
    }
    return dp[n][sum];
}

int main(){
//    freopen("/Users/pradithaalwis/Downloads/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
