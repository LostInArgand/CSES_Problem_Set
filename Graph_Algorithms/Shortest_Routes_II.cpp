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


ll dist[500][500];

void floydWarshal(ll graph[][500]){
	memset(dist, -1, sizeof(dist));
	for(int i = 0; i < 500; i++){
		for(int j = 0; j< 500;j++){
			dist[i][j] = graph[i][j];
			dist[j][j] = 0;
			}
		dist[i][i] = 0;
		}
	for(int k = 0; k < 500; k++){
		for(int i = 0; i < 500; i++){
			for(int j = 0; j< 500;j++){
				if((dist[k][j] != -1) && (dist[i][k] != -1) && (dist[i][j] == -1 || (dist[i][j] > dist[i][k] + dist[k][j]))){
					dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	int a, b;
	ll c;
	ll graph[500][500];
	memset(graph, -1, sizeof(graph));
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		if (graph[a - 1][b - 1] != -1){
			graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
			graph[b - 1][a - 1] = min(graph[b - 1][a - 1], c);
			}
		else{
			graph[a - 1][b - 1] = c;
			graph[b - 1][a - 1] = c;
			}
		}
	floydWarshal(graph);
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		cout << dist[a - 1][b - 1] << '\n';;
	 	}
	
	return 0;
}
