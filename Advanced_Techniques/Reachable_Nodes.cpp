#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>

#define MOD 1000000007

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
    list<int> *adj;
    bitset<50001> *mem;
    int Nchildren[50001]{};

public:
    int V;
    explicit Graph(int V);
    void addEdge(int u, int v);
    void solve();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V + 1];
    mem = new bitset<50001>[50001];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    Nchildren[v]++;
}

void Graph::solve(){
    queue<int> q;
    for(int i=1; i <= V; i++){
        mem[i].set(i);
        if(Nchildren[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            mem[v] |= mem[u];
            Nchildren[v]--;
            if(Nchildren[v] == 0) q.push(v);
        }
    }
    for(int i=1; i <= V; i++){
        cout << mem[i].count() << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    int a, b;
    for(int i=0; i < m; i++){
        cin >> a >> b;
        graph.addEdge(b, a);
    }
    graph.solve();
    return 0;
}
