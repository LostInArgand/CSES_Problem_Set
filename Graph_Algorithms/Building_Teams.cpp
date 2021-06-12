#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
 
typedef long long int ll;
//typedef    unordered_map<int, int> umap;
//typedef    unordered_set<int> uset;
 
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define testcase(T) for(int t = 1; t <= T; t++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define uset unordered_set<int>
#define unmap unordered_map<int, int>
#define MOD 1000000007
# define inf 0x3f3f3f3f
 
 
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
	int V;
	list<int> * adj;
	int ans[100005];
	bool visited[100005];
	bool possible;
	public:
		Graph(int V);
		void addEdge(int u, int v);
		void solve();
		void bfs(int u);
	};
	
Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V + 1];
	memset(ans, -1, sizeof(ans));
	memset(visited, false, sizeof(visited));
	possible = true;
	}
 
void Graph::addEdge(int u, int v){
	adj[u].PB(v);
	adj[v].PB(u);
	}
	
void Graph::solve(){
	for(int i = 1; i <= V; i++){
		if(!possible){
		cout << "IMPOSSIBLE";
		return;
		}
		if(!visited[i]){
			bfs(i);
			}
		}
	if(!possible){
		cout << "IMPOSSIBLE";
		return;
		}
	for(int i = 1; i <= V; i++){
		cout << ans[i] + 1<< ' ';
		}
	}
	
void Graph::bfs(int start){
	queue<pair<int, int>> q;
	q.push({start, 0});
	ans[start] = 0;
	int u, v, count;
	list<int>::iterator itr;
	while(!q.empty()){
		u = q.front().F;
		count = q.front().S;
		q.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
			v = *itr;
			if(!visited[v]){
				if(ans[v] == count){
					possible = false;
					return;
					}
				q.push({v, 1 - count});
				ans[v] = 1 - count;
				}
			}
		}
	}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Graph graph(n);
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		graph.addEdge(a, b);
		}
	graph.solve();
	return 0;
}
