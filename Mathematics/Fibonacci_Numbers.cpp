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
map<ll, ll> mem;

ll fibo(ll n){
	if(mem.count(n)){
		return mem[n];
		}
	if(n & 1){
		mem[n] = (fibo(n / 2) * fibo((n / 2) + 1) + fibo((n / 2) - 1)* fibo(n / 2)) % MOD;
		}
	else{
		mem[n] = (fibo(n / 2) * fibo(n / 2) + fibo((n / 2) - 1)* fibo((n / 2) - 1)) % MOD;
		}
	return mem[n];
	}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mem[-1] = 0;
    mem[0] = 1;
    mem[1] = 1;
	ll n;
	cin >> n;
	cout << fibo(n - 1);
	return 0;
}
