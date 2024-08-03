#include<bits/stdc++.h>


typedef long long ll;

using namespace std;

int num_paths = 0;
int n = 7;
int m = 7;
bool visited[7][7];

bool check(int x, int y, int u, int v){
    if (0 <= x + u && x + u < n){
        if (0 <= y + v && y + v < m) return true;
    }
    return false;
}

void solve(string &path, int i, int x, int y){
    if (i == 48){
        num_paths += (x == n - 1) && (y == 0);
        return;
    }
    if(i > 48) return;
    if (x == n - 1 && y == 0) return;
    // Left and Right visited
    if((!check(x, y, 0, -1) || visited[x][y - 1]) && (!check(x, y, 0, 1) || visited[x][y + 1])){
        if(check(x, y, -1, 0) && !visited[x - 1][y] && check(x, y, 1, 0) && !visited[x + 1][y]) return;
    }
    if(!check(x, y, -1, 0) || visited[x - 1][y]){ // Up visited or cannot go up
        if((!check(x, y, 1, 0) || visited[x + 1][y])){ // Bottom Visited
            if(check(x, y, 0, -1) && !visited[x][y - 1] && check(x, y, 0, 1) && !visited[x][y + 1]) return; // Left and Right uvisited
        }
        if ((!check(x, y, 0, 1) || visited[x][y + 1]) && (check(x, y, -1, 1) && !visited[x - 1][y + 1])) return; // Top Right Diagonal Unvisited
        if ((!check(x, y, 0, -1) || visited[x][y - 1]) && (check(x, y, -1, -1) && !visited[x - 1][y - 1])) return; // Top Left Diagonal Unvisited
    }
    visited[x][y] = true;
    switch(path[i]){
        case '?':
            if(check(x, y, -1, 0) && !visited[x - 1][y]) solve(path, i + 1, x - 1, y); // Up
            if(check(x, y, 1, 0) && !visited[x + 1][y]) solve(path, i + 1, x + 1, y); // Down
            if(check(x, y, 0, -1) && !visited[x][y - 1]) solve(path, i + 1, x, y - 1); // Left
            if(check(x, y, 0, 1) && !visited[x][y + 1]) solve(path, i + 1, x, y + 1); // Right
            break;
        case 'U':
            if(check(x, y, -1, 0) && !visited[x - 1][y]) solve(path, i + 1, x - 1, y);
            break;
        case 'D':
            if(check(x, y, 1, 0) && !visited[x + 1][y]) solve(path, i + 1, x + 1, y);
            break;
        case 'L':
            if(check(x, y, 0, -1) && !visited[x][y - 1]) solve(path, i + 1, x, y - 1);
            break;
        case 'R':
            if(check(x, y, 0, 1) && !visited[x][y + 1]) solve(path, i + 1, x, y + 1);
            break;
    }
    visited[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<bool>> visited(7, vector<bool>(7, false));
    string path;
    cin >> path;
    solve(path, 0, 0, 0);
    cout << num_paths << endl;
    return 0;
}
