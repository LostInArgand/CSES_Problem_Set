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
#define inf 0x3f3f3f3f
 
 
using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    multiset<int> tickets;
    int inp;
    for(int i = 0; i < n; i++){
		cin >> inp;
		tickets.insert(-inp);
		}
		
	multiset<int> :: iterator low;
	for(int i = 0; i < m; i++){
		cin >> inp;
		low = tickets.lower_bound(-inp);
		if(low == tickets.end()) cout << -1 << '\n';
		else{
			cout << abs(*low) << '\n';
			tickets.erase(low);
			}
		}
	return 0;
}
