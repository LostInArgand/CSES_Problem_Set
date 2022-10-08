#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>

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

unordered_set<string> visited;
vector<int> edges;

void dfs(const string& curr_node, int& k, string& A){
    for(int i=0; i<k; i++){
        string next_node = curr_node + A[i];
        if(visited.find(next_node) == visited.end()){
            visited.insert(next_node);
            dfs(next_node.substr(1), k, A);
            edges.push_back(i);
        }
    }
}

string deBruijn(int n, int k, string A){
    visited.clear();
    edges.clear();

    string start = string(n - 1, A[0]);
    dfs(start, k, A);
    int length = pow(k, n);
    string ans;
    for(int i=0; i<length; i++){
        ans += A[edges[i]];
    }
    ans += start;
    return ans;
}


int main() {
//    freopen("/Users/pradithaalwis/CLionProjects/csesPractice/test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string A = "01";
    cout << deBruijn(n, 2, A) << endl;
    return 0;
}
