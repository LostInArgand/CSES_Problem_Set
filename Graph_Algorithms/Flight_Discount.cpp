#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>

typedef long long int ll;


using namespace std;


int max(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}

int min(int x, int y){
    if (x <= y){
        return x;
    }
    return y;
}

ll fastExpo(ll i, ll j, ll mod){
    ll res = 1;
    i = i % mod;
    if(j == 0){
        return 1;
    }
    if(i == 0){
        return 0;
    }
    while (j > 0){
        if((j & 1) == 1){
            res = (res * i) % mod;
        }
        j >>= 1;
        i = (i * i) % mod;
    }
    return res;
}


class Graph{

public:
    int V;
    Graph(int V);
    list<pair<int, ll>> * adj;
    void addEdge(int u, int v, ll w);
    vector<ll> dijkstra(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int, ll>>[V + 1];
}

void Graph::addEdge(int u, int v, ll w){
    adj[u].emplace_back(v, w);
}

vector<ll> Graph::dijkstra(int start){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<ll> dist(V + 1, -1);
    pq.push(make_pair(0, start));
    dist[start] = 0;
    list<pair<int, ll>>::iterator itr;
    int visited[100005];
    memset(visited, 0, sizeof(visited));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
            int v = (*itr).first;
            ll w = (*itr).second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
            if(dist[v] == -1){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

void solve(Graph graphS, Graph graphM){
    vector<ll> distS = graphS.dijkstra(1);
    vector<ll> distM = graphM.dijkstra(graphM.V);
    ll ans = LONG_LONG_MAX;
    list<pair<int, ll>> :: iterator itr;
    for(int u = 1; u <= graphS.V; u++){
        for(itr = graphS.adj[u].begin(); itr != graphS.adj[u].end(); ++itr){
            int v = (*itr).first;
            ll w = (*itr).second;
            ll temp = distS[u] + (w/2) + distM[v];
            if((distS[u] != -1) && (distM[v] != -1)) ans = min(ans, temp);
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    Graph graphS(n);
    Graph graphM(n);
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graphS.addEdge(a, b, c);
        graphM.addEdge(b, a, c);
    }
    solve(graphS, graphM);
    return 0;
}
