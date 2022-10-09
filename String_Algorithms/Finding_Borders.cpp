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

void zarray(string word, int *z){
    int n = (int) word.length();
    int L = 0, R = 0, k;
    for(int i=1; i<n; i++){
        if(i > R){
            L = R = i;
            while(R < n && word[R - L] == word[R]) R++;

            z[i] = R - L;
            R--;
        }
        else{
            k = i - L;
            if(z[k] < R - i + 1) z[i] = z[k];
            else{
                L = i;
                while(R < n && word[R - L] == word[R]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }
}


int main() {
//    freopen("/Users/pradithaalwis/CLionProjects/csesPractice/test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    cin >> word;
    int z[word.length()];
    zarray(word, z);
    int len = (int) word.length();
    vector<int> ans;
    for(int i=0; i < len; i++){
        if(z[i] == len - i) {
            ans.push_back(z[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto ele: ans) cout << ele << ' ';
    return 0;
}
