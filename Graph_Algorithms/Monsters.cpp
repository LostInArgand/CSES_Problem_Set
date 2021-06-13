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
char grid[1000][1000];
int monst[1000][1000];
bool visited[1000][1000];
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	memset(monst, -1, sizeof(monst));
	queue<pair<int, int>> q;
	pair<int, int> start;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 'A'){
				start = {i, j};
				}
			else if(grid[i][j] == 'M'){
				q.push({i, j});
				monst[i][j] = 0;
				}
			}
		}
	memset(visited, false, sizeof(visited));
	int x, y;
	while(!q.empty()){
		x = q.front().F;
		y = q.front().S;
		q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = true;
		if(isValid(x, y - 1, n, m) && grid[x][y - 1] != '#' && !visited[x][y - 1] && (monst[x][y - 1] == -1 || monst[x][y - 1] > monst[x][y] + 1)){
			monst[x][y - 1] = monst[x][y] + 1;
			q.push({x, y - 1});
			}
		if(isValid(x, y + 1, n, m) && grid[x][y + 1] != '#' && !visited[x][y + 1] && (monst[x][y + 1] == -1 || monst[x][y + 1] > monst[x][y] + 1)){
			monst[x][y + 1] = monst[x][y] + 1;
			q.push({x, y + 1});
			}
		if(isValid(x - 1, y, n, m) && grid[x - 1][y] != '#' && !visited[x - 1][y] && (monst[x - 1][y] == -1 || monst[x - 1][y] > monst[x][y] + 1)){
			monst[x - 1][y] = monst[x][y] + 1;
			q.push({x - 1, y});
			}
		if(isValid(x + 1, y, n, m) && grid[x + 1][y] != '#' && !visited[x + 1][y] && (monst[x + 1][y] == -1 || monst[x + 1][y] > monst[x][y] + 1)){
			monst[x + 1][y] = monst[x][y] + 1;
			q.push({x + 1, y});
			}
		}
	assert(q.empty());
	int count = 0;
	q.push({start.F * m + start.S, count});
	memset(visited, false, sizeof(visited));
	unordered_map<int, pair<int, char>> mem;
	bool found = false;
	pair<int, int> end;
	while(!q.empty()){
		x = q.front().F / m;
		y = q.front().F % m;
		count = q.front().S;
		q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = true;
		if(x == 0 || y == 0 || x == n - 1 || y == m - 1){
			found = true;
			end = {x, y};
			break;
			}
		if(isValid(x, y - 1, n, m) && grid[x][y - 1] != '#' && !visited[x][y - 1] && (monst[x][y - 1] == -1 || monst[x][y - 1] > count + 1)){
			mem[x * m + y - 1] = {x * m + y, 'L'};
			q.push({x*m + y - 1, count + 1});
			}
		if(isValid(x, y + 1, n, m) && grid[x][y + 1] != '#' && !visited[x][y + 1] && (monst[x][y + 1] == -1 || monst[x][y + 1] > count + 1)){
			mem[x * m + y + 1] = {x * m + y, 'R'};
			q.push({x*m + y + 1, count + 1});
			}
		if(isValid(x - 1, y, n, m) && grid[x - 1][y] != '#' && !visited[x - 1][y] && (monst[x - 1][y] == -1 || monst[x - 1][y] > count + 1)){
			mem[(x - 1) * m + y] = {x * m + y, 'U'};
			q.push({(x - 1) * m + y, count + 1});
			}
		if(isValid(x + 1, y, n, m) && grid[x + 1][y] != '#' && !visited[x + 1][y] && (monst[x + 1][y] == -1 || monst[x + 1][y] > count + 1)){
			mem[(x + 1) * m + y] = {x * m + y, 'D'};
			q.push({(x + 1) * m + y, count + 1});
			}
		}
	if(found){
		vector<char> ans;
		while(end.F != start.F || end.S != start.S){
			x = end.F;
			y = end.S;
			ans.PB(mem[x*m + y].S);
			end = {mem[x*m + y].F / m, mem[x*m + y].F % m};
			}
		cout << "YES" << '\n' << ans.size() << '\n';
		for(auto itr = ans.rbegin(); itr != ans.rend(); ++itr){
			cout << *itr;
			}
		}
	else{
		cout << "NO";
		}
	return 0;
}
