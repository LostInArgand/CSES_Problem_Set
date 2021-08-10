#include <bits/stdc++.h>
#include <iostream>

typedef long long int ll;

using namespace std;

int n, x, inp;
int dp[1000001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> x;
	int coins[n];
	for(int i = 0; i < n; i++){
		cin >> coins[i];
		}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(coins[j] <= i && dp[i - coins[j]] != -1){
				if(dp[i] == -1){
					dp[i] = dp[i - coins[j]] + 1;
					}
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
	cout << dp[x];
	return 0;
}
