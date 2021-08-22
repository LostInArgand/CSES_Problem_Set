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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    int n, m;
	cin >> n >> m >> k;
	ll desire[n];
	ll apartments[m];
	
	for(int i = 0; i < n; i++){
		cin >> desire[i];
	}
	for(int i = 0; i < m; i++){
		cin >> apartments[i];
	}
	
	sort(desire, desire + n);
	sort(apartments, apartments + m);
	int ans = 0;
	int i = 0, j = 0;
	while(i < n && j < m){
		if(desire[i] - k > apartments[j]){
			j++;
			}
		else if(desire[i] + k < apartments[j]){
			i++;
			}
		else{
			ans++;
			i++;
			j++;
			}
		}
	cout << ans;
	return 0;
}
