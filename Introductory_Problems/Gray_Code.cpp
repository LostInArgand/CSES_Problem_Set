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

vector<pair<int, int>> ans;

vector<string> solve(int n){
	if(n == 0){
		return {"0"};
		}
	if(n == 1){
		return {"0", "1"};
		}
	vector<string> rep = solve(n - 1);
	vector<string> ans;
	for(auto itr = rep.begin(); itr != rep.end(); itr++){
		ans.PB("0" + *itr);
		}
	for(auto itr = rep.rbegin(); itr != rep.rend(); itr++){
		ans.PB("1" + *itr);
		}
	return ans;
	}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> ans = solve(n);
	for(auto itr = ans.begin(); itr != ans.end(); itr++){
		cout << *itr << '\n';
		}
	return 0;
}
