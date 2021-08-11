#include <bits/stdc++.h>
#include <iostream>

typedef long long int ll;

using namespace std;

int n, x;
int dp[1001][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >>x;
	int prices[n], pages[n];
	for(int i = 0; i < n; i++) cin >> prices[i];
	for(int i = 0; i < n; i++) cin >> pages[i];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= x; j++){
			if(j < prices[i - 1]){
				dp[i][j] = dp[i - 1][j];
				continue;
				}
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
			}
		}
	cout << dp[n][x];
	return 0;
}
