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


ll solve(ll i, ll j){
	ll ans = 0;
	ll maxx = max(i, j);
	if (i == maxx){
		if(i & 1){
			ans = (i - 1) * (i - 1) + j;
			}
		else{
			ans = i * i - j + 1;
			}
		}
	else{
		if(j & 1){
			ans = j * j - i + 1;
			}
		else{
			ans = (j - 1) * (j - 1) + i;
			}
		}
	return ans;
	}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, x, y;
	cin >> t;	
	for(int i = 0; i < t; i++){
		cin >> x >> y;
		ll ans = solve(x, y);
		cout << ans << '\n';
		}
	return 0;
}
