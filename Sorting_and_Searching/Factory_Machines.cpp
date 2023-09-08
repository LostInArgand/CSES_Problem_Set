#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

#define xlim 1010
#define ylim 1010

typedef long long ll;

using namespace std;

bool check(ll x, int t, const ll * arr, int n){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += min(x / arr[i], (ll)1e9);
    }
    return sum >= t;
}
ll solve(ll * arr, int n, int t){
    ll l = 0, r = 1e18, m;
    while(l < r){
        m = (l + r) / 2;
        if (check(m, t, arr, n)) r = m;
        else l = m + 1;
    }
    return l;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    ll arr[n];
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    cout << solve(arr, n, t) << endl;
    return 0;
}
