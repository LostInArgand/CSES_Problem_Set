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

void heap_push(priority_queue<pair<int, int>> &heap, set<int> &heap_set, int &count, int val, int index){
    heap.push(make_pair(val, index));
    heap_set.insert(index);
    count++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, inp;
    cin >> n >> k;
    if(k == 1){
        for(int i = 0; i < n; i++){
            cin >> inp;
            cout << inp << ' ';
        }
        return 0;
    }

    priority_queue<pair<int, int>> max_h, min_h;
    set<int> min_set, max_set;
    int min_count = 0, max_count = 0;
    vector<pair<int, int>> window;
    for(int i = 0; i < k; i++){
        cin >> inp;
        window.emplace_back(inp, i);
    }
    sort(window.begin(), window.end());

    for(int i = 0; i < k / 2; i++){
        max_h.push(make_pair(window[i].first, window[i].second));
        max_set.insert(window[i].second);
        max_count++;
    }
    for(int i = k / 2; i < k; i++){
        min_h.push(make_pair(-window[i].first, window[i].second));
        min_set.insert(window[i].second);
        min_count++;
    }
    if(k % 2) cout << -min_h.top().first << ' ';
    else cout << max_h.top().first << ' ';
    bool flag = true;
    for(int i = k; i < n; i++){
        // Remove out of window elements
        if(min_set.find(i - k) != min_set.end()){
            min_set.erase(i - k);
            min_count--;
            flag = false;
        }
        if(max_set.find(i - k) != max_set.end()){
            max_set.erase(i - k);
            max_count--;
            flag = true;
        }
//        cout << "OK" << max_h.size() << endl;
        while(!min_h.empty() && min_h.top().second + k <= i) min_h.pop();
        while(!max_h.empty() && max_h.top().second + k <= i) max_h.pop();

        // Add the new element to the smaller heap
        cin >> inp;
        if(flag) heap_push(max_h, max_set, max_count, inp, i);
        else heap_push(min_h, min_set, min_count, -inp, i);

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
            heap_push(max_h, max_set, max_count, abs(min_top.first), min_top.second);
            heap_push(min_h, min_set, min_count, -max_top.first, max_top.second);
            while(min_h.top().second + k <= i) min_h.pop();
            while(max_h.top().second + k <= i) max_h.pop();
        }
        if(k % 2) cout << -min_h.top().first << ' ';
        else cout << max_h.top().first << ' ';
    }
    return 0;
}
