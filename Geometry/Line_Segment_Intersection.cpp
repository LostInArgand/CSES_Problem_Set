//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <complex>


#define MOD 1000000007

typedef long long ll;


using namespace std;


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

ll cross_product(complex<ll> a, complex<ll> b){
    return (conj(a) * b).imag();
}

bool diff_sign(ll a, ll b){
    if(a == 0 && b != 0) return true;
    if(a != 0 && b == 0) return true;
    if(a > 0 && b < 0) return true;
    if(a < 0 && b > 0) return true;
    return false;
}

bool on_same_line(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    complex<ll> a = {x1, y1};
    complex<ll> b = {x2, y2};
    complex<ll> c = {x3, y3};
    complex<ll> d = {x4, y4};

    vector<pair<ll, ll>> points;
    points.emplace_back(x1, y1);
    points.emplace_back(x2, y2);
    points.emplace_back(x3, y3);
    points.emplace_back(x4, y4);

    // On the same line
    ll cp1 = cross_product(c - a, c - b);
    ll cp2 = cross_product(d - a, d - b);

    sort(points.begin(), points.end());

    if(cp1 == 0 && cp2 == 0){
        // First points is from segment 1
        if(points[0] == make_pair(x1, y1) or points[0] == make_pair(x2, y2)){
            if(points[1] == make_pair(x3, y3) or points[1] == make_pair(x4, y4)) return true;
            return false;
        }
        // First points is from segment 2
        else{
            if(points[1] == make_pair(x1, y1) or points[1] == make_pair(x2, y2)) return true;
            return false;
        }
    }
    return false;
}

bool edge_point_common(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    complex<ll> a = {x1, y1};
    complex<ll> b = {x2, y2};
    complex<ll> c = {x3, y3};
    complex<ll> d = {x4, y4};
    if(a == c or a == d or b == c or b == d) return true;
    return false;
}

bool intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    complex<ll> a = {x1, y1};
    complex<ll> b = {x2, y2};
    complex<ll> c = {x3, y3};
    complex<ll> d = {x4, y4};
    ll cp1 = cross_product(c - a, c - b);
    ll cp2 = cross_product(d - a, d - b);
    ll cp3 = cross_product(a - c, a - d);
    ll cp4 = cross_product(b - c, b - d);

    if(diff_sign(cp1, cp2) && diff_sign(cp3, cp4)) return true;
    return false;
}

int main(){
//    freopen("/Users/pradithaalwis/Downloads/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        bool rep = on_same_line(x1, y1, x2, y2, x3, y3, x4, y4);
        if(rep){
            cout << "YES" << endl;
            continue;
        }

        rep = edge_point_common(x1, y1, x2, y2, x3, y3, x4, y4);
        if(rep){
            cout << "YES" << endl;
            continue;
        }
        rep = intersect(x1, y1, x2, y2, x3, y3, x4, y4);
        if(rep){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
