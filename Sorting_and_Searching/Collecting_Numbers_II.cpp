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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr;
	int mem[n];
	for(int i = 0; i < n; i++){
		cin >> mem[i];
		arr.PB(MP(mem[i], i + 1));
		}
	sort(arr.begin(), arr.end());
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(arr[i].S < arr[i - 1].S){
			ans++;
			}
		}
	int a, b, before = 0, after = 0;;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		int val1 = mem[a - 1] - 1, val2 = mem[b - 1] - 1;
		before = 0;
		if((val1 - 1 >= 0) && (arr[val1].S < arr[val1 - 1].S)){
			before++;
			}
		if((val1 + 1 < n) && (arr[val1 + 1].S < arr[val1].S)){
			before++;
			}
		if((val2 - 1 >= 0) &&(val2 - 1 != val1)&& (arr[val2].S < arr[val2 - 1].S)){
			before++;
			}
		if((val2 + 1 < n) &&(val2 + 1 != val1) && (arr[val2 + 1].S < arr[val2].S)){
			before++;
			}
		swap(arr[val1].S, arr[val2].S);
		swap(mem[a-1], mem[b-1]);
		after = 0;
		if((val1 - 1 >= 0) && (arr[val1].S < arr[val1 - 1].S)){
			after++;
			}
		if((val1 + 1 < n) && (arr[val1 + 1].S < arr[val1].S)){
			after++;
			}
		if((val2 - 1 >= 0) &&(val2 - 1 != val1)&& (arr[val2].S < arr[val2 - 1].S)){
			after++;
			}
		if((val2 + 1 < n) &&(val2 + 1 != val1) && (arr[val2 + 1].S < arr[val2].S)){
			after++;
			}
		ans = ans - before + after;
		cout << ans << '\n';
		}
	return 0;
}
