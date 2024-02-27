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
    vector<vector<ll>> original_cap;
    set<int> reachable;
    vector<int> path;
public:
    explicit Graph(int V);
    void addEdge(int u, int v);
    void aug_paths();
    ll BFS();
    bool DFS(int u);
};

Graph::Graph(int V){
    numVertices = V;
    adjLists = new list<int>[V + 1];
    parent = new int[numVertices + 1];
    capacity.resize(V + 1, vector<ll>(V + 1, 0));
    original_cap.resize(V + 1, vector<ll>(V + 1, 0));
}

void Graph::addEdge(int u, int v){
    adjLists[u].push_front(v);
    adjLists[v].push_front(u);
    capacity[u][v] = 1;
    original_cap[u][v] = 1;
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

bool Graph::DFS(int u){
    if(u == numVertices) return true;
    for(auto v : adjLists[u]){
        if(original_cap[u][v] != 0 && capacity[u][v] == 0){
            bool rep = DFS(v);
            if (rep){
                capacity[u][v] = -1;
                path.push_back(v);
                return true;
            }
        }
    }
    return false;
}

void Graph::aug_paths() {
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
    cout << flow << endl;
    while(true){
        path.clear();
        bool rep = DFS(1);
        path.push_back(1);
        if(rep){
            cout << path.size() << endl;
            vector<int> :: reverse_iterator ritr;
            for(ritr = path.rbegin(); ritr != path.rend(); ++ritr){
                cout << *ritr << ' ';
            }
            cout << endl;
            continue;
        }
        return;
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
    g.aug_paths();
    return 0;
}
