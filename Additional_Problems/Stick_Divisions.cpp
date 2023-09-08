#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

typedef long long ll;

using namespace std;

ll solve(vector<ll> & arr){
    if (arr.size() == 1){
        return 0;
    }
    ll a = arr.front();
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();
    ll b = arr.front();
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();
    arr.push_back(a + b);
    push_heap(arr.begin(), arr.end());
    ll ans = -(a + b);
    ans += solve(arr);
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, n, inp;
    cin >> x >> n;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        cin >> inp;
        arr.push_back(-inp);
    }
    make_heap(arr.begin(), arr.end());
    cout << solve(arr) << endl;
    return 0;
}
