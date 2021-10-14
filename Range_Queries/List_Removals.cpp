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
    ll n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
		cin >> arr[i];
		}
	//~ Position array
	ll position[n+1];
	position[0] = 0;
	for(int i = 1; i <= n; i++){
		position[i] = 1;
		}
	ll *BITree = constructBITree(position, n+1);
	ll inp;
	for(int i = 0; i < n; i++){
		cin >> inp;
		//~ Binary Search
		ll start = 0, end = n, mid = 0;
		while(start <= end){
			mid = (start + end) / 2;
			if(getSum(BITree, mid) > inp){
				end = mid - 1;
				}
			else if(getSum(BITree, mid) < inp){
				start = mid + 1;
				}
			else{
				if(position[mid]){
					break;
					}
				else{
					end = mid - 1;
					}
				}
			}
		cout << arr[mid - 1] << ' ';
		updateBIT(BITree, n + 1, mid, 0-position[mid]);
		position[mid] = 0;
		}
	return 0;
}
