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
    vector<pair<ll, ll>> ranges;
    map<pair<ll, ll>, int> mem;
    ll x, y;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        ranges.push_back(make_pair(x, -y));
        mem.insert(make_pair(make_pair(x, -y), i));
    }
    sort(ranges.begin(), ranges.end());
    ll max_right = -1;
    ll others_in_me[n], in_some_other[n];
    for(int i = 0; i < n; i++){
        auto it = mem.find(ranges[i]);
        if (abs(ranges[i].second) <= max_right){
            in_some_other[it->second] = 1;
        }
        else{
            in_some_other[it->second] = 0;
            max_right = abs(ranges[i].second);
        }
    }
    ll min_right = 1000000001;
    for(int i = n - 1; i >= 0; i--){
        auto it = mem.find(ranges[i]);
        if(abs(ranges[i].second) >= min_right){
            others_in_me[it->second] = 1;
        }
        else{
            others_in_me[it->second] = 0;
            min_right = abs(ranges[i].second);
        }
    }
    for(int i = 0; i < n; i++){
        cout << others_in_me[i] << ' ';
    }
    cout << '\n';
    
    for(int i = 0; i < n; i++){
        cout << in_some_other[i] << ' ';
    }
    return 0;
}
