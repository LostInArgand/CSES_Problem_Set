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

typedef long long ll;

using namespace std;

ll const INF = 1000000000000000;


class Graph{
    int numVertices;
    list<int> *adjLists;
    int *parent;
    vector<vector<ll>> capacity;
    set<int> reachable;
    bool *visited;
public:
    explicit Graph(int V);
    void addEdge(int u, int v);
    void min_cut();
    ll BFS();
    void DFS(int u);
};

Graph::Graph(int V){
    numVertices = V;
    adjLists = new list<int>[V + 1];
    parent = new int[numVertices + 1];
    capacity.resize(V + 1, vector<ll>(V + 1, 0));
    visited = new bool[V + 1];
}

void Graph::addEdge(int u, int v){
    adjLists[u].push_front(v);
    adjLists[v].push_front(u);
    capacity[u][v] += 1;
    capacity[v][u] += 1;
}

ll Graph::BFS(){
    memset(parent, -1, (numVertices + 1) * sizeof(int));
    parent[1] = -2;
    queue<pair<int, ll>> q;
    q.push(make_pair(1, INF));
    int cur;
    ll flow, new_flow;
    while(!q.empty()){
        cur = q.front().first;
        flow = q.front().second;
        q.pop();
        for (int next : adjLists[cur]){
            if(parent[next] == -1 && capacity[cur][next]){
                parent[next] = cur;
                new_flow = min(flow, capacity[cur][next]);
                if (next == numVertices) return new_flow;
                q.push(make_pair(next, new_flow));
            }
        }
    }
    return 0;
}

void Graph::DFS(int u){
    visited[u] = true;
    reachable.insert(u);
    for(auto v : adjLists[u]){
        if(!visited[v] && (capacity[u][v] > 0)) DFS(v);
    }
}
void Graph::min_cut() {
    ll flow = 0;
    ll new_flow;
    int cur, prev;
    while((new_flow = BFS())){
        flow += new_flow;
        cur = numVertices;
        while(cur != 1){
            prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    DFS(1);
    vector<pair<int, int>> edges;
    for(auto u : reachable){
        for(auto v : adjLists[u]){
            if((reachable.find(v) == reachable.end()) && capacity[u][v] == 0){
                edges.emplace_back(u, v);
            }
        }
    }
    cout << edges.size() << endl;
    for(auto ele : edges){
        cout << ele.first << ' ' << ele.second << endl;
    }
}



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, u, v;
    cin >> n >> m;
    auto g = Graph(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g.addEdge(u, v);

    }
    g.min_cut();
    return 0;
}
