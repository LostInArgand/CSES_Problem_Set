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
 
int n;
int mem[200010];
 
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
 
int fastExpo(ll i, ll j){
	ll res = 1;
	i = i % MOD;
	if(j == 0){
		return 1;
		}
	if(i == 0){
		return 0;
		}
	while (j > 0){
		if((j & 1) == 1){
			res = (res * i) % MOD;
			}
		j >>= 1;
		i = (i * i) % MOD;
		}
	return res;
	}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	ll a, b;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		cout << fastExpo(a, b)<< '\n';
		}
}
