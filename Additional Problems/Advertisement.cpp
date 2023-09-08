#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

typedef long long ll;

using namespace std;

ll solve(const vector<ll> & arr){
    ll max_area = 0, top, area;
    stack<ll> s;
    int i = 0, n = (int) arr.size();
    while (i < n){
        if(s.empty() || arr[s.top()] <= arr[i]) s.push(i++);
        else{
            top = s.top();
            s.pop();
            area = arr[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area);
        }
    }
    while(!s.empty()){
        top = s.top();
        s.pop();
        area = arr[top] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, inp;
    cin >> n;
    vector<ll> arr;
    for(int i=0; i < n; i++){
        cin >> inp;
        arr.push_back(inp);
    }
    cout << solve(arr) << endl;
    return 0;
}
