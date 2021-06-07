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
	string s;
	map<char, int> mem;
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++){
		mem[s[i]]++;
		}
	map<char, int>::iterator itr;
	char ans1[(int)s.size() / 2];
	char ans2[(int)s.size() / 2];
	char ans3;
	int x = 0, y = ((int)s.size() / 2) - 1;
	int count = 0;
	for(itr = mem.begin(); itr != mem.end(); ++itr){
		if ((*itr).S % 2 != 0){
			count++;
			ans3 = (*itr).F;
			(*itr).S--;
			}
		if((count > 1) || ((count == 1) && ((int)s.size() % 2 == 0))){
			cout << "NO SOLUTION";
			return 0;
			}
		for(int i = 0; i < (*itr).S; i += 2){
			ans1[x] = (*itr).F;
			x++;
			ans2[y] = (*itr).F;
			y--;
			}
		}
	if(count > 1){
		cout << "NO SOLUTION";
		return 0;
		}
	for(int i = 0; i < (int)s.size() / 2; i++){
		cout << ans1[i];
		}
	if(count == 1){
		cout << ans3;
		}
	for(int i = 0; i < (int)s.size() / 2; i++){
		cout << ans2[i];
		}
	return 0;
}
