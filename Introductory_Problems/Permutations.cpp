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

bool isValid(int i, int j){
	if(i >= 7 || j >= 7 || i < 0 || j < 0){
		return false;
		}
	return true;
	}


vector<int> solve(int n){
	vector<int> arr;
	if(n == 1){
		arr.PB(1);
		return arr;
		}
	if(n == 2 || n == 3){
		return arr;
		}
	if(n == 4){
		arr.PB(2);
		arr.PB(4);
		arr.PB(1);
		arr.PB(3);
		return arr;
		}
	for(int i = 1; i <= n; i+=2){
		arr.PB(i);
		}
	for(int i = 2; i <= n; i+=2){
		arr.PB(i);
		}
	return arr;
	}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	vector<int> ans = solve(n);
	if(ans.size() == 0){
		cout << "NO SOLUTION";
		return 0;
		}
	for(auto i = ans.begin(); i != ans.end(); ++i){
		cout << *i << ' ';
		}
	return 0;
}
