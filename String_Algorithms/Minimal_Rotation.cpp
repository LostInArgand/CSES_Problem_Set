#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>

#define MOD 1000000007

typedef long long int ll;


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

int least_rotation(string s){
    int n = (int) s.length();
    int f[2*n];
    memset(f, -1, sizeof(int) * 2 * n);
    int k = 0;
    for(int j=1; j < 2*n; j++){
        int i = f[j - 1 - k];
        while(i != -1 && s[j % n] != s[(k + i + 1) % n]){
            if(s[j % n] < s[(k + i + 1) % n]) k = j - i - 1;
            i = f[i];
        }
    }
    return 0;
}

vector<pair<int, string>> duval(string const& s) {
    int n = (int) s.length();
    int i = 0;
    vector<pair<int, string>> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.emplace_back(i, s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}

int main() {
//    freopen("/Users/pradithaalwis/CLionProjects/csesPractice/test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    cin >> word;
    int n = (int) word.length();
    word += word;
    int prev = 0;
    for(const auto& ele:duval(word)) {
        if(ele.first >= n) break;
        prev = ele.first;
    }
    cout << word.substr(prev, n);
    return 0;
}
