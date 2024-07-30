#include<bits/stdc++.h>


typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    for(ll x = 1; x <= n; x++){
        ll ans = ((x * x - 3 * x + 4L) * (x + 4L) * (x - 1L)) / 2L;
        cout << ans << endl;
    }
    return 0;
}
