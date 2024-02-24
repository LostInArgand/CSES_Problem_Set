#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <list>
#include <cstring>

#define xlim 1010
#define ylim 1010

typedef long long ll;

using namespace std;

vector<int> parent, ranks;

struct Edge{
    int u, v, weight;
    bool operator<(Edge const& other) const{
        return weight < other.weight;
    }
};

int find_set(int u){
    if (u == parent[u]) return u;
    parent[u] = find_set(parent[u]);
    return parent[u];
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if (ranks[u] < ranks[v]) {
        parent[u] = v;
    }
    else if(ranks[u] > ranks[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        ranks[u]++;
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, u, v, w;
    cin >> n >> m;
    vector<Edge> edges;
    ll num_edges = 0, cost = 0;
    parent.resize(n);
    ranks.resize(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        ranks[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        Edge ed = {u - 1, v - 1, w};
        edges.push_back(ed);
    }
    sort(edges.begin(), edges.end());
    for (Edge e : edges){
        if(find_set(e.u) != find_set(e.v)){
            cost += e.weight;
            num_edges += 1;
            union_set(e.u, e.v);
        }
    }
    if (num_edges == n - 1) {
        cout << cost << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
