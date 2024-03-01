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

const ll MIN = -1e15;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
    multiset<ll> mem;
    ll ans = MIN;
    for(int i = 0; i + a <= n; i++){
        if(i + a > b){
            auto itr = mem.find(prefix[i + a - b - 1]);
            mem.erase(itr);
        }
        mem.insert(prefix[i]);
        ans = max(ans, prefix[i + a] - *mem.begin());
    }
    cout << ans << endl;
    return 0;
}
