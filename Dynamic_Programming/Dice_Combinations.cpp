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

unordered_map<int, int> mem;
int solve(int n){
	int ans = 0;
	if(n <= 6 && n > 1){
		ans++;
		}
	if(n < 0){
		return 0;
		}
	unordered_map<int, int> :: iterator itr;
	itr = mem.find(n);
	if(itr != mem.end()){
		return (*itr).S;
		}
	for(int i = 6; i > 0; i--){
		ans = (ans + solve(n - i)) % MOD;
		}
	mem.insert({n, ans});
	return ans;
	}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	mem.insert({0, 0});
	mem.insert({1, 1});
	int ans = solve(n);
	cout << ans;
	return 0;
}
