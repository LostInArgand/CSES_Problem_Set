#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

ll solve(ll x){
    ll nine_d = 9;
    for(ll i = 1; i < 18; i++){
        ll range = i * nine_d;
        if(x - range < 0){
            ll d = ((ll) pow(10, i - 1)) - 1L + (x / i);
            ll rem = x % i;
            if(rem != 0){
                d++;
                ll ans = d / (ll)pow(10, i - rem);
                ans %= 10;
                return ans;
            }
            ll ans = d % 10;
            return ans;
        }
        x -= range;
        nine_d *= 10;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    ll k;
    for(int t = 0; t < q; t++){
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}
