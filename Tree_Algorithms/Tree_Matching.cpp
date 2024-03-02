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

class Graph{
    int V;
    list<int> *edges;
    ll *dp1;
    ll *dp2;
    bool *visited;

public:
    explicit Graph(int V);
    void addEdge(int u, int v);
    ll DFS1(int u);
    ll DFS2(int u);
    ll solve();
};

Graph::Graph(int V) {
    this->V = V;
    edges = new list<int>[V + 1];
    dp1 = new ll[V + 1];
    dp2 = new ll[V + 1];
    visited = new bool[V + 1];
    memset(dp1, -1, (V + 1) * sizeof(ll));
    memset(dp2, -1, (V + 1) * sizeof(ll));
}

void Graph::addEdge(int u, int v) {
    edges[u].push_front(v);
    edges[v].push_front(u);
}

ll Graph::DFS1(int u){
    if(dp1[u] != -1) return dp1[u];
    visited[u] = true;
    ll ans = 0;
    for(auto v : edges[u]){
        if(!visited[v]) ans = max(ans, DFS2(v) + 1 + DFS2(u) - max(DFS2(v), DFS1(v)));
    }
    visited[u] = false;
    dp1[u] = ans;
    return dp1[u];
}

ll Graph::DFS2(int u){
    if(dp2[u] != -1) return dp2[u];
    ll summ = 0;
    visited[u] = true;
    for(auto v : edges[u]){
        if(!visited[v]) summ += max(DFS1(v), DFS2(v));
    }
    visited[u] = false;
    dp2[u] = summ;
    return dp2[u];
}

ll Graph::solve(){
    return max(DFS1(1), DFS2(1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, u, v;
    cin >> n;
    auto graph = Graph(n);
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    cout << graph.solve() << endl;
    return 0;
}
