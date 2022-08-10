#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
 
 
typedef long long int ll;
 
using namespace std;
 
ll solve(){
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a, b;
    cin >> n;
    
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<pair<int, int>, int>> arr;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        arr.push_back(make_pair(make_pair(a, b), i));
    }
    sort(arr.begin(), arr.end());
    
    int allocation[n];
    int max_room = 1;
    pq.push(make_pair(arr[0].first.second, 1));
    int room_number = 1;
    allocation[arr[0].second] = room_number;
    for(int i = 1; i < n; i++){
        if(pq.top().first < arr[i].first.first){
            room_number = pq.top().second;
            pq.pop();
        }
        else{
            max_room++;
            room_number = max_room;
        }
        pq.push(make_pair(arr[i].first.second, room_number));
        allocation[arr[i].second] = room_number;
    }
    cout << max_room << '\n';
    for(int i = 0; i < n; i++){
        cout << allocation[i] << ' ';
    }
    return 0;
}
