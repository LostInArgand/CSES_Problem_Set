#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <list>
#include <cstring>
#include <queue>
#include <map>
#include <complex>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<ll, ll> pre_mem;
    ll inp, prefix_sum = 0;
    ll ans = 0;
    pre_mem[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> inp;
        prefix_sum += inp;
        if(pre_mem.find((n + (prefix_sum % n)) % n) != pre_mem.end()){
            ans += pre_mem[(n + (prefix_sum % n)) % n]++;
        }
        else pre_mem[(n + (prefix_sum % n)) % n] = 1;
    }
    cout << ans << endl;
    return 0;
}
