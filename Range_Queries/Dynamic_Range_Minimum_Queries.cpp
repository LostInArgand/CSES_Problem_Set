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

int recConsSegTree(int arr[], int start, int end, int *segTree, int ind){
	if(start == end){
		segTree[ind] = arr[start];
		return arr[start];
		}
	int mid = (start + end) / 2;
	segTree[ind] = min(recConsSegTree(arr, start, mid, segTree, ind*2 + 1), recConsSegTree(arr, mid + 1, end, segTree, ind*2 + 2));
	return segTree[ind];
	}

int *constructSegTree(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int maxSize = 2*(int)pow(2,x) - 1;
	
	int *segTree = new int[maxSize];
	recConsSegTree(arr, 0, n - 1, segTree, 0);
	return segTree;
	}

int rangeMin(int *segTree, int start, int end, int qstart, int qend, int ind){
	
	if(qstart <= start && qend >= end){
		return segTree[ind];
		}
	if(end < qstart || start > qend){
		return INT_MAX;
		}
	int mid = (start + end) / 2;
	return min(rangeMin(segTree, start, mid, qstart, qend, 2*ind + 1), rangeMin(segTree, mid + 1, end, qstart, qend, 2*ind+2));
	}

void updateSegTree(int arr[], int *segTree, int start, int end, int ind, int val, int node){
	if(start == end){
		arr[ind] = val;
		segTree[node] = val;
		}
	else{
		int mid = (start + end) / 2;
		if(ind >= start && ind <= mid){
			updateSegTree(arr, segTree, start, mid, ind, val, 2 * node + 1);
			}
		else{
			updateSegTree(arr, segTree, mid + 1, end, ind, val, 2 * node + 2);
			}
		segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
		}
	return;
	}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		}
	int *segTree = constructSegTree(arr, n);
	int a, b, k;
	for(int i = 0; i < q; i++){
		cin >> k >> a >> b;
		if (k == 1){
			updateSegTree(arr, segTree, 0, n - 1, a - 1, b, 0);
			}
		else{
			cout << rangeMin(segTree, 0, n - 1, a - 1, b - 1, 0) << '\n';
			}
		}
	return 0;
}
