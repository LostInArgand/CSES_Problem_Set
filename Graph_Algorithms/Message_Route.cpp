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
	
	public:
		Graph(int V);
		void addEdge(int u, int v);
		void bfs(int s);
	};
	
Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V + 1];
	}
 
void Graph::addEdge(int u, int v){
	adj[u].PB(v);
	adj[v].PB(u);
	}
	
void Graph::bfs(int start){
	queue<int> q;
	unordered_map<int, int> mem;
	list<int>::iterator itr;
	bool visited[V + 1];
	memset(visited, false, sizeof(visited));
	int dist[V + 1];
	memset(dist, -1, sizeof(dist));
	q.push(start);
	dist[start] = 0;
	int u, v;
	while(!q.empty()){
		u = q.front();
		q.pop();
		if(visited[u]) continue;
		visited[u] = true;
		if(u == V){
			break;
			}
		for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
			v = *itr;
			if(!visited[v]){
				q.push(v);
				if(dist[v] == -1 || dist[v] > dist[u]+1){
					mem[v] = u;
					dist[v] = dist[u] + 1;
					}
				}
			}
		}
	if(u != V){
		cout << "IMPOSSIBLE";
		return;
		}
	vector<int> ans;
	int i = V;
	while(i != 1){
		ans.PB(i);
		i = mem[i];
		}
	ans.PB(1);
	cout << ans.size() << '\n';
	for(auto itr = ans.rbegin(); itr != ans.rend(); ++itr){
		cout << *itr << ' ';
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
	graph.bfs(1);
	return 0;
}
