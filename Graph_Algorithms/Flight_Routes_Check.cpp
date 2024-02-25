#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <list>
#include <cstring>

typedef long long ll;

using namespace std;

ll const MOD = 1000000007;


class Graph{
    int numVertices;
    list<int> *adjLists;

public:
    bool *visited;
    explicit Graph(int V);
    void addEdge(int u, int v);
    void DFS(int u);
};

Graph::Graph(int V){
    numVertices = V;
    adjLists = new list<int>[V];
    visited = new bool[V];
}

void Graph::addEdge(int u, int v){
    adjLists[u].push_front(v);
}

void Graph::DFS(int u) {
    visited[u] = true;
    for (auto v : adjLists[u]){
        if (!visited[v]) DFS(v);
    }
}

void solve(Graph & g, Graph & g_rev, int n){
    g.DFS(0);
    int node = -1;
    for(int i=0; i < n; i++){
        if (!g.visited[i]){
            node = i + 1;
            break;
        }
    }
    if (node != -1){
        cout << "NO" << endl;
        cout << 1 << ' ' << node << endl;
        return;
    }
    g_rev.DFS(0);
    node = -1;
    for (int i = 0; i < n; i++){
        if(!g_rev.visited[i]){
            node = i + 1;
            break;
        }
    }
    if (node != -1){
        cout << "NO" << endl;
        cout << node << ' ' << 1 << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, u, v;
    cin >> n >> m;
    auto g = Graph(n);
    auto g_reverse = Graph(n);
    for(int i = 0; i < m; i++){
        cin >> u >> v ;
        g.addEdge(u - 1, v - 1);
        g_reverse.addEdge(v - 1, u - 1);
    }
    solve(g, g_reverse, n);
    return 0;
}
