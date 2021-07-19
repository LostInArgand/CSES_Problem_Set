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

bool isValid(int x, int y, int n, int m){
	if(x < 0 || x >= n || y < 0 || y >= m){
		return false;
		}
	return true;
	}

vector<int> subord[200001];
int ans[200001];
bool visited[200001];

int dfs(int u){
	visited[u] = true;
	ans[u] = 0;
	for(int v:subord[u]){
		if(!visited[v]){
			ans[u] += dfs(v) + 1;
			}
		}
	return ans[u];
	}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, inp;
	cin >> n;
	memset(visited, 0, sizeof(visited));
	for(int i = 2; i <= n; i++){
		cin >> inp;
		subord[i].PB(inp);
		subord[inp].PB(i);
		}
	dfs(1);
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
		}
	return 0;
}
