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
    ll *subtree_num;
    ll *ans;

public:
    explicit Graph(int V);
    void addEdge(int u, int v);
    ll DFS1(int u, int parent);
    void DFS2(int u, int parent);
    void solve();
};

Graph::Graph(int V) {
    this->V = V;
    edges = new list<int>[V + 1];
    subtree_num = new ll[V + 1];
    ans = new ll[V + 1];
    memset(subtree_num, 0, (V + 1) * sizeof(ll));
}

void Graph::addEdge(int u, int v) {
    edges[u].push_front(v);
    edges[v].push_front(u);
}

ll Graph::DFS1(int u, int parent){
    ll summ = 0;
    for(auto v : edges[u]){
        if (v != parent){
            summ += DFS1(v, u) + subtree_num[v];
            subtree_num[u] += subtree_num[v];
        }
    }
    subtree_num[u]++;
    return summ;
}

void Graph::DFS2(int u, int parent){
    if(u != 1) ans[u] = ans[parent] + V - 2 * subtree_num[u];
    for(auto v : edges[u]){
        if (v != parent){;
            DFS2(v, u);
        }
    }
}

void Graph::solve(){
    ans[1] = DFS1(1, 0);
    DFS2(1, 0);
    for(int i = 1; i <= V; i++){
        cout << ans[i] << ' ';
    }
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
    graph.solve();
    return 0;
}
