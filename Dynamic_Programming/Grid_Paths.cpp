#include <bits/stdc++.h>
#include <iostream>

typedef long long int ll;

using namespace std;

int n;
int dp[1001][1001];
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	char grid[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> grid[i][j];
			}
		}
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(grid[i][j] == '*'){
				dp[i][j] = 0;
				continue;
				}
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	cout << dp[n][n];
	return 0;
}
