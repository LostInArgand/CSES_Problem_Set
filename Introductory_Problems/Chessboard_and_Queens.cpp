#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

void solve(int queen, vector<string> & grid, bool *column, bool *l_diag, bool *r_diag, ll & count){
    if (queen == 8){
        // cout << count << endl;
        count++;
        return;
    }
    for(int i = 0; i < 8; i++){
        if (!(column[i] || l_diag[7 - queen + i] || r_diag[queen + i]) && grid[queen][i] == '.'){
            // cout << queen << ' ' << i << endl;
            column[i] = true;
            l_diag[7 - queen + i] = true;
            r_diag[queen + i] = true;
            solve(queen + 1, grid, column, l_diag, r_diag, count);
            column[i] = false;
            l_diag[7 - queen + i] = false;
            r_diag[queen + i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> grid(8);
    for(int i = 0; i < 8; i++) cin >> grid[i];
    bool column[8];
    bool l_diag[15];
    bool r_diag[15];
    memset(column, 0, sizeof(column));
    memset(l_diag, 0, sizeof(l_diag));
    memset(r_diag, 0, sizeof(r_diag));
    ll count = 0;
    solve(0, grid, column, l_diag, r_diag, count);
    cout << count << endl;
    return 0;
}
