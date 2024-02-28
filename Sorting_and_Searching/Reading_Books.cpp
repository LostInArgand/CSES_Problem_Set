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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, inp, maxx = 0, summ = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inp;
        maxx = max(maxx, inp);
        summ += inp;
    }
    cout << max(summ, 2 * maxx) << endl;
    return 0;
}
