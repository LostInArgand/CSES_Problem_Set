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
	list<pair<int, ll>> * adj;
	
	public:
		Graph(int V);
		void addEdge(int u, int v, ll w);
		void dijkstra(int s);
	};
	
Graph::Graph(int V){
	this->V = V;
	adj = new list<pair<int, ll>>[V + 1];
	}
 
void Graph::addEdge(int u, int v, ll w){
	adj[u].PB(MP(v, w));
	}
	
void Graph::dijkstra(int start){
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> dist(V + 1, -1);
	pq.push(MP(0, start));
	dist[start] = 0;
	list<pair<int, ll>>::iterator itr;
	int visited[100005];
	memset(visited, 0, sizeof(visited));
	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
			int v = (*itr).F;
			ll w = (*itr).S;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(MP(dist[v], v));
				}
			if(dist[v] == -1){
				dist[v] = dist[u] + w;
				pq.push(MP(dist[v], v));
				}
			}
		}
	for(int i = 1; i < V + 1; i++){
		cout << dist[i] << ' ';
		}
	}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Graph graph(n);
	int a, b, c;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		graph.addEdge(a, b, c);
		}
	graph.dijkstra(1);
	return 0;
}
