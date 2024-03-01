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

void heap_push(priority_queue<pair<int, int>> &heap, set<int> &heap_set, int &count, ll &summ, int val, int index){
    heap.push(make_pair(val, index));
    heap_set.insert(index);
    count++;
    summ += abs(val);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, inp;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;

    sort(arr.begin(), arr.end());

    multiset<int> end_times;
    for(int i = 0; i < k; i++) end_times.insert(0);
    ll ans = 0;
    for(auto ele : arr){
        auto itr = end_times.upper_bound(ele.second);
        if(itr == end_times.begin()) continue;
        end_times.erase(--itr);
        end_times.insert(ele.first);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
