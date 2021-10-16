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
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
		ll x1,x2,x3,y1,y2,y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if((y2 - y1)*(x3 - x1) > (y3 - y1)*(x2 - x1)){
			cout << "RIGHT" << '\n';
			}
		else if((y2 - y1)*(x3 - x1) < (y3 - y1)*(x2 - x1)){
			cout << "LEFT" << '\n';
			}
		else{
			cout << "TOUCH" << '\n';
			}
		}
	return 0;
}
