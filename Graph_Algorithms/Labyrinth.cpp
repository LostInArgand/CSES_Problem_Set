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
	
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	char grid[n][m];
	pair<int, int> a, b;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 'A'){
				a = MP(i , j);
				}
			if(grid[i][j] == 'B'){
				b = MP(i , j);
				}
			}
		}
	int visited[n * m];
	memset(visited, 0, sizeof(visited));
	visited[a.F * m + a.S] = 1;
	queue<pair<int, int>> q;
	unordered_map<int, pair<int, char>> mem;
	q.push(a);
	int x, y, tempPos;
	bool found = false;
	while(!q.empty()){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if(x == b.F && y == b.S){
			found = true;
			break;
			}
		if(isValid(x, y - 1, n, m) && grid[x][y] != '#' && !visited[x * m + y - 1]){
			tempPos = x * m + y - 1;
			q.push(MP(x, y - 1));
			mem[tempPos] = {x*m + y, 'L'};
			visited[x * m + y - 1] = 1;
			}
		if(isValid(x, y + 1, n, m) && grid[x][y] != '#' && !visited[x * m + y + 1]){
			tempPos = x * m + y + 1;
			q.push(MP(x, y + 1));
			mem[tempPos] = {x*m + y, 'R'};
			visited[x * m + y + 1] = 1;
			}
		if(isValid(x - 1, y, n, m) && grid[x][y] != '#' && !visited[(x - 1) * m + y]){
			tempPos = (x - 1) * m + y;
			q.push(MP(x - 1, y));
			mem[tempPos] = {x*m + y, 'U'};
			visited[(x - 1) * m + y] = 1;
			}
		if(isValid(x + 1, y, n, m) && grid[x][y] != '#' && !visited[(x + 1) * m + y]){
			tempPos = (x + 1) * m + y;
			q.push(MP(x + 1, y));
			mem[tempPos] = {x*m + y, 'D'};
			visited[(x + 1) * m + y] = 1;
			}
		}
	if(found){
		cout << "YES" << '\n';
		int next;
		next = b.F * m + b.S;
		vector<char> ans;
		while(next != (a.F * m + a.S)){
			ans.PB(mem[next].S);
			next = mem[next].F;
			}
		cout << ans.size() << '\n';
		for(auto itr = ans.rbegin(); itr != ans.rend(); ++itr){
			cout << *itr;
			}
		}
	else{
		cout << "NO";
		}
	return 0;
}
