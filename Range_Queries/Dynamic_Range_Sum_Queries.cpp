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

ll getSum(ll BITree[], ll ind){
	ll sum = 0;
	ind++;
	while(ind > 0){
		sum += BITree[ind];
		ind -= ind &(-ind);
		}
	return sum;
	}

void updateBIT(ll BITree[], ll n, ll ind, ll val){
	ind++;
	while(ind <= n){
		BITree[ind] += val;
		ind += (ind & (-ind));
		}
	}

ll *constructBITree(ll arr[], ll n){
	ll *BITree = new ll[n+1];
	for(int i = 1; i<=n; i++){
		BITree[i] = 0;
		}
	for(int i = 0; i < n; i++){
		updateBIT(BITree, n, i, arr[i]);
		}
	return BITree;
	}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, q;
	cin >> n >> q;
	n++;
	ll arr[n];
	arr[0] = 0;
	for(int i = 1; i < n; i++){
		cin >> arr[i];
		}
	ll *BITree = constructBITree(arr, n);
	ll k, a, b;
	for(int i = 0; i < q; i++){
		cin >> k >> a >> b;
		if(k == 1){
			updateBIT(BITree, n, a, b - arr[a]);
			arr[a] = b;
			}
		else{
			ll ans = getSum(BITree, b) - getSum(BITree, a - 1);
			cout << ans << '\n';
			
			}
		}
	return 0;
}
