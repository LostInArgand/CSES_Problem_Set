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

int n, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++) pos.emplace_back(MP(arr[i], i + 1));
	sort(pos.begin(), pos.end());
	bool found = false;
	int pos1, pos2, pos3;
	for(int i = 0; i < n; i++){
		pos1 = pos[i].second;
		for(int j = i + 1; j < n; j++){
			pos2 = pos[j].second;
			if(pos1 == pos2) continue;
			int find = x - pos[i].F - pos[j].F;
			if(find <= 0) continue;
			// Binary search
			int left = 0;
			int right = n - 1;
			while(left <= right){
				int mid = (left + right) / 2;
				if(pos[mid].F == find && pos[mid].S != pos1 && pos[mid].S != pos2){
					found = true;
					pos3 = pos[mid].S;
					break;
					}
				if(pos[mid].F > find){
					right = mid - 1;
					}
				else{
					left = mid + 1;
					}
				}
			if(found) break;
			}
		if(found) break;
		}
	if(found){
		cout << pos1 << ' ' << pos2 << ' ' << pos3;
		}
	else{
		cout << "IMPOSSIBLE";
		}
	return 0;
}
