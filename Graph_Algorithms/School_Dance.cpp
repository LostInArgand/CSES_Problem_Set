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
    int n_boys;
    list<int> *adjLists;
    vector<int> matched;
    vector<bool> seen;
public:
    explicit Graph(int n, int m);
    void addEdge(int u, int v);
    void bi_partite_match();
    bool kuhn(int u);
};

Graph::Graph(int n, int m){
    n_boys = n;
    numVertices = n + m;
    adjLists = new list<int>[n + m + 1];
    matched.resize(n + m + 1);
    seen.resize(n + m + 1);
}

void Graph::addEdge(int u, int v){
    adjLists[u].push_front(v);
}

bool Graph::kuhn(int u){
    if (seen[u]) return false;
    seen[u] = true;
    for(auto v : adjLists[u]){
        if (matched[v] == -1 || kuhn(matched[v])){
            matched[v] = u;
            return true;
        }
    }
    return false;
}

void Graph::bi_partite_match() {
    matched.assign(numVertices + 1, -1);
    for(int i = 1; i <= n_boys; i++){
        seen.assign(numVertices + 1, false);
        kuhn(i);
    }
    vector<pair<int, int>> pairs;
    for(int i = n_boys + 1; i <= numVertices; i++){
        if(matched[i] != -1) pairs.emplace_back(matched[i], i - n_boys);
    }
    cout << pairs.size() << endl;
    for(auto ele : pairs){
        cout << ele.first << ' ' << ele.second << endl;
    }
}



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    auto g = Graph(n, m);
    for (int i = 0; i < k; i++) {
        cin >> u >> v;
        g.addEdge(u, n + v);
    }
    g.bi_partite_match();
    return 0;
}
