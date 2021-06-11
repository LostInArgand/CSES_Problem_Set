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
	void DFS(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void connectedComp();
	};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V + 1];
	}
	
void Graph::connectedComp(){
	bool visited[V + 1];
	memset(visited, false, sizeof(visited));
	vector<int> ans;
	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			ans.PB(i);
			DFS(i, visited);
			}
		}
	cout << ans.size() - 1 << '\n';
	for(int i = 1; i < (int)ans.size(); ++i){
		cout << ans[i - 1] << ' ' << ans[i] << '\n';
		}
	}
	
void Graph::DFS(int u, bool visited[]){
	list<int>::iterator itr;
	int v;
	visited[u] = true;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		v = *itr;
		if(!visited[v]){
			DFS(v, visited);
			}
		}
	}
void Graph::addEdge(int u, int v){
	adj[u].PB(v);
	adj[v].PB(u);
	}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, u, v;
	cin >> n >> m;
	Graph graph(n);
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph.addEdge(u, v);
		}
	graph.connectedComp();
	return 0;
}
