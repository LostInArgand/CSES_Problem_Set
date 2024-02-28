#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <list>
#include <cstring>
#include <queue>
#include <map>
#include <complex>

typedef long long ll;

using namespace std;

struct FenwickTree{
    vector<int> bit;
    int n;

    explicit FenwickTree(int n){
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    explicit FenwickTree(vector<int> a) : FenwickTree(a.size()){
        for (size_t i = 0; i < a.size(); i++){
            add(i, a[i]);
        }
    }

    void add(int i, int val){
        for(++i; i < n; i += (i & -i)) bit[i] += val;
    }

    int sum(int i){
        int summ = 0;
        for(++i; i > 0; i -= (i & -i)) summ += bit[i];
        return summ;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};


bool compare1(const pair<pair<int, int>, int> &i, const pair<pair<int, int>, int> &j){
    return i.first.second < j.first.second;
}

bool compare2(const pair<int, int> &i, const pair<int, int> &j){
    if(i.first == j.first){
        return i.second > j.second;
    }
    return i.first < j.first;
}

bool compare3(const pair<int, int> &i, const pair<int, int> &j){
    if(i.first == j.first){
        return i.second < j.second;
    }
    return i.first > j.first;
}

void solve(int n, vector<pair<pair<int, int>, int>> ranges){
    map<pair<int,int>, int> mem;
    int i = 0;
    vector<pair<int, int>> range_compressed;
    sort(ranges.begin(), ranges.end(), compare1);
    i = 1;
    int prev = -1;
    for(auto ele : ranges){
        if (ele.first.second == prev){
            range_compressed.emplace_back(ele.first.first, i - 1);
            mem[make_pair(ele.first.first, i - 1)] = ele.second;
        }
        else{
            range_compressed.emplace_back(ele.first.first, i);
            mem[make_pair(ele.first.first, i++)] = ele.second;
            prev = ele.first.second;
        }
    }
    sort(range_compressed.begin(), range_compressed.end(), compare2);

    FenwickTree ftree_1(n);
    vector<int> other_us(n);
    int count = 0;
    for(auto p : range_compressed){
        other_us[mem[p]] = count - ftree_1.sum(p.second - 1);
        ftree_1.add(p.second, 1);
        count++;
    }

    sort(range_compressed.begin(), range_compressed.end(), compare3);
    FenwickTree ftree_2(n);
    vector<int> us_others(n);
    for(auto p : range_compressed){
        us_others[mem[p]] = ftree_2.sum(p.second);
        ftree_2.add(p.second, 1);
    }
    for(auto ele : us_others) cout << ele << ' ';
    cout << endl;
    for(auto ele : other_us) cout << ele << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r;
    vector<pair<pair<int, int>, int>> ranges;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        ranges.emplace_back(make_pair(l, r), i);
    }
    solve(n, ranges);
    return 0;
}
