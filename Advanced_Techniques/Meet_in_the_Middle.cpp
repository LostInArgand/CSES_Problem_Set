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

typedef long long ll;

using namespace std;

vector<ll> calculate_subsets(const ll *arr, int n, int start, bool mem_type, ll x){
    vector<ll> ans;
    for(int i=0; i < (1 << n); i++){
        ll sum = 0L;
        for(int j=0; j < n; j++){
            if(i & (1<<j)) sum += arr[start + j];
        }
        if(mem_type){
            ans.push_back(x - sum);
        }
        else{
            ans.push_back(sum);
        }
    }
    return ans;
}

void solve(const ll *arr, int n, ll x){
    vector<ll> arr1 = calculate_subsets(arr, n/2, 0, false, x);
    vector<ll> arr2 = calculate_subsets(arr, n - (n / 2), n/2, true, x);
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    ll ans = 0;
    for(ll u : arr1){
        auto low_itr = lower_bound(arr2.begin(), arr2.end(), u);
        auto high_itr = upper_bound(arr2.begin(), arr2.end(), u);
        ans += (high_itr - arr2.begin()) - (low_itr - arr2.begin());
    }
    cout << ans << endl;
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
    return 0;
}
