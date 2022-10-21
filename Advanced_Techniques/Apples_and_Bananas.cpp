#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>

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

const int SIZE = 1<<19;
const double PI = acos(-1);
vector<complex<double>> A(SIZE), B(SIZE);

void fft(vector<complex<double>> &a, bool inv){
    int N = (int) a.size();

    for(int i = 1, j = 0; i < N; i++){
        int bit = N >> 1;       // N is a power of two
        for(; j & bit; bit >>= 1){
            j ^= bit;
        }
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for(int len = 2; len <= N; len <<= 1){
        double theta = 2 * PI / len * (inv ? -1 : 1);
        complex<double> wlen(cos(theta), sin(theta));
        for(int i = 0; i < N; i += len){
            complex<double> w(1);
            for(int j = 0; j < len / 2; j++){
                complex<double> u = a[i + j], v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (inv){
        for(complex<double> &z : a) z /= N;
    }
}

void solve(int k){
    fft(A, false);
    fft(B, false);

    for(int i = 0; i < SIZE; i++){
        A[i] *= B[i];
    }

    fft(A, true);
    for(int i = 2; i <= 2*k; i++){
        cout << llround(A[i].real()) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, m;
    cin >> k >> n >> m;
    for(int i = 0, inp; i < n; i++){
        cin >> inp;
        A[inp] += 1;
    }
    for(int i = 0, inp; i < m; i++){
        cin >> inp;
        B[inp] += 1;
    }

    solve(k);
    return 0;
}
