#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


typedef long long int ll;

using namespace std;

ll solve(){
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    int n, a, d;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> d;
        ans += d;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    ll sum = arr[0];
    ans -= sum;
    for(int i = 1; i < n; i++){
        sum += arr[i];
        ans -= sum;
    }
    cout << ans;
    return 0;
}
