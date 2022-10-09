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

struct TrieNode{
    struct TrieNode *children[26]{};
    bool isWord{};
};

struct TrieNode *getNode(){
    auto *pNode = new TrieNode;
    pNode->isWord = false;
    for(auto & i : pNode->children){
        i = nullptr;
    }
    return pNode;
}

void insertString(struct TrieNode *root, const string& word){
    struct TrieNode *pCrawl = root;
    for(char i : word){
        int ind = i - 'a';
        if(!pCrawl->children[ind]) pCrawl->children[ind] = getNode();
        pCrawl = pCrawl->children[ind];
    }
    pCrawl->isWord = true;
}


ll solve(struct TrieNode *root, const string& word){
    ll dp[word.size() + 1];
    memset(dp, 0, sizeof(ll)*(word.size() + 1));
    dp[word.length()] = 1;
    for(int i=(int) word.length() - 1; i>=0; i--){
        int j = i;
        struct TrieNode *currNode = root;
        while(j < (int)word.length() and currNode->children[word[j] - 'a']){
            currNode = currNode->children[word[j] - 'a'];
            if(currNode->isWord) dp[i] = (dp[i] + dp[j + 1]) % MOD;
            j++;
        }
    }
    return dp[0];
}

int main() {
//    freopen("/Users/pradithaalwis/CLionProjects/csesPractice/test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    cin >> word;
    int k;
    cin >> k;

    struct TrieNode *root = getNode();
    string str;
    for(int i=0; i<k; i++){
        cin >> str;
        insertString(root, str);
    }

    ll ans = solve(root, word);
    cout << ans << endl;
    return 0;
}
