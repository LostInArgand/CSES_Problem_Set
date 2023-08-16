#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long ll;

using namespace std;

ll polygonArea(const vector<pair<ll, ll>>& edges){
    ll area = 0;
    ll u, v;
    u = edges.back().first;
    v = edges.back().second;
    for(auto i: edges){
        area += (i.first - u) * (i.second + v);
        u = i.first;
        v = i.second;
    }
    area = abs(area);
    return area;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    vector<pair<ll, ll>> edges;
    ll u, v;
    while (t--) {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    cout << polygonArea(edges) << endl;
    return 0;
}
