#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

int linc[200001];
int union_size[200001];

int find(int x){
    if(x == linc[x]) return x;
    return linc[x] = find(linc[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (union_size[a] < union_size[b]) swap(a, b);
    union_size[a] += union_size[b];
    linc[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q, u, v;
    cin >> n >> m >> q;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    pair<int, int> queries[q + 1];
    pair<int, int> ranges[q + 1];
    for(int i = 0; i < q; i++){
        cin >> u >> v;
        queries[i + 1] = make_pair(u, v);
        ranges[i + 1] = make_pair(1, m);
    }
    vector<queue<int>> time(m + 1);
    int ans[q + 1];
    memset(ans, -1, sizeof(ans));
    int i = 0;
    while(i <= ceil(log2(m))){
        for(int k = 1; k <= q; k++){
            int mid = (ranges[k].first + ranges[k].second) / 2;
            time[mid].push(k);
        }
        for(int t = 1; t <= n; t++){
            linc[t] = t;
            union_size[t] = 1;
        }
        for(int j = 1; j <= m; j++){
            u = edges[j - 1].first;
            v = edges[j - 1].second;
            unite(u, v);
            while(!time[j].empty()){
                int qry = time[j].front();
                time[j].pop();
                if(find(queries[qry].first) == find(queries[qry].second)){
                    ranges[qry] = make_pair(ranges[qry].first, j);
                    ans[qry] = j;
                }
                else ranges[qry] = make_pair(j + 1, ranges[qry].second);
            }
        }
        i++;
    }
    for(int tau = 1; tau <= q; tau++){
        if(queries[tau].first == queries[tau].second) cout << 0 << endl;
        else cout << ans[tau] << endl;
    }
    return 0;
}
