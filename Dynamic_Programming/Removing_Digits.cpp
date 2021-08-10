#include <bits/stdc++.h>
#include <iostream>

typedef long long int ll;

using namespace std;

int n, inp;
int dp[1000001];
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		int temp = i;
		for(int j = 0; j <= (int) log10(i); j++){
			if ((temp % 10) == 0){
				temp /= 10;
				continue;
				}
			if(dp[i] == -1) dp[i] = dp[i - (temp % 10)] + 1;
			dp[i] = min(dp[i], dp[i - (temp % 10)] + 1);
			temp /= 10;
			}
		}
	cout << dp[n];
	return 0;
}
