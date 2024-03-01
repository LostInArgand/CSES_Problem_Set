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
    if(k == 1){
        for(int i = 0; i < n; i++){
            cin >> inp;
            cout << 0 << ' ';
        }
        return 0;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<pair<int, int>> max_h, min_h;
    set<int> min_set, max_set;
    int min_count = 0, max_count = 0;
    vector<pair<int, int>> window;
    for(int i = 0; i < k; i++){
        window.emplace_back(arr[i], i);
    }
    sort(window.begin(), window.end());

    ll min_sum = 0, max_sum = 0;
    for(int i = 0; i < k / 2; i++){
        max_sum += window[i].first;
        max_h.push(make_pair(window[i].first, window[i].second));
        max_set.insert(window[i].second);
        max_count++;
    }
    for(int i = k / 2; i < k; i++){
        min_sum += window[i].first;
        min_h.push(make_pair(-window[i].first, window[i].second));
        min_set.insert(window[i].second);
        min_count++;
    }
    ll median =  k % 2 ? -min_h.top().first : max_h.top().first;
    ll cost = max_count * median - max_sum + (min_sum - median * min_count);
    cout << cost << ' ';
    bool flag = false;
    for(int i = k; i < n; i++){
        // Remove out of window elements
        if(min_set.find(i - k) != min_set.end()){
            min_set.erase(i - k);
            min_count--;
            flag = false;
            min_sum -= arr[i - k];
        }
        if(max_set.find(i - k) != max_set.end()){
            max_set.erase(i - k);
            max_count--;
            flag = true;
            max_sum -= arr[i - k];
        }
        while(!min_h.empty() && min_h.top().second + k <= i) min_h.pop();
        while(!max_h.empty() && max_h.top().second + k <= i) max_h.pop();

        // Add the new element to the smaller heap
        if(flag) heap_push(max_h, max_set, max_count, max_sum, arr[i], i);
        else heap_push(min_h, min_set, min_count, min_sum,-arr[i], i);

        // Balance the heaps
        while(max_h.top().first > (-min_h.top().first)){
            pair<int, int> max_top = max_h.top();
            pair<int, int> min_top = min_h.top();
            max_h.pop();
            min_h.pop();
            max_set.erase(max_top.second);
            min_set.erase(min_top.second);
            max_count--;
            min_count--;
            max_sum -= arr[max_top.second];
            min_sum -= arr[min_top.second];
            heap_push(max_h, max_set, max_count, max_sum, abs(min_top.first), min_top.second);
            heap_push(min_h, min_set, min_count, min_sum, -max_top.first, max_top.second);
            while(min_h.top().second + k <= i) min_h.pop();
            while(max_h.top().second + k <= i) max_h.pop();
        }

        median =  k % 2 ? -min_h.top().first : max_h.top().first;
        cost = max_count * median - max_sum + (min_sum - median * min_count);
        cout << cost << ' ';
    }
    return 0;
}
