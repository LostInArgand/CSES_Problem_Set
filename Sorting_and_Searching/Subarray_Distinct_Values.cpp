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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    map<int, int> mem;
    int j = 0;
    int i = 0;
    ll ans = 0;
    int unique = 0;
    while(i < n){
        // Fill upto k
        while(j < n && (unique < k || mem[arr[j]] > 0)){
            mem[arr[j]]++;
            if(mem[arr[j]] == 1) unique++;
            j++;
        }
        ans += j - i;
        mem[arr[i]]--;
        if(mem[arr[i]] == 0) unique--;
        i++;
    }
    cout << ans << endl;
    return 0;
}
