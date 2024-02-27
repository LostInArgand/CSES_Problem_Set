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

void solve(int n, int m){
    fft(A, false);
    fft(B, false);

    for(int i = 0; i < SIZE; i++){
        A[i] *= B[i];
    }
    fft(A, true);
    for(int i = 0; i < n + m - 1; i++) cout << llround(abs(A[i])) << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, inp;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> inp;
        A[i] = inp;
    }
    for(int i = 0; i < m; i++){
        cin >> inp;
        B[m - i - 1] = inp;
    }
    solve(n, m);
    return 0;
}
