// CP template (macOS-friendly)
// - Fast IO, small helpers, optional debug
// - Works with Apple Clang and Homebrew GCC
// - Toggle local debug with: -DLOCAL

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>
#include <chrono>
#include <functional>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

constexpr ll INF64 = (ll)4e18;
constexpr int INF32 = (int)2e9;
constexpr int MOD = 1'000'000'007; // change per problem

// ---------- fast io ----------
static inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ---------- random ----------
static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
struct RNG {
    uint64_t s;
    RNG(uint64_t seed = chrono::steady_clock::now().time_since_epoch().count())
        : s(splitmix64(seed)) {}
    uint64_t operator()() { return s = splitmix64(s); }
    uint64_t operator()(uint64_t l, uint64_t r) { // inclusive
        return l + (operator()() % (r - l + 1));
    }
} rng;

// ---------- debug ----------
#ifdef LOCAL
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
template<class T> void debug_one(const char* name, const T& x){ cerr<<name<<"="<<x<<" "; }
template<class T, class... R>
void debug_out(const char* names, const T& x, const R&... rest){
    const char* c = names;
    int depth = 0;
    while (*c && (*c!=',' || depth)) { 
        if (*c=='('||*c=='{'||*c=='[') depth++;
        if (*c==')'||*c=='}'||*c==']') depth--;
        cerr<<*c++; 
    }
    cerr<<"="<<x;
    if constexpr (sizeof...(rest)){ cerr<<", "; debug_out(c+1, rest...); }
    else cerr<<"\n";
}
#else
#define dbg(...)
#endif

// ---------- helpers ----------
template<class T> inline bool chmin(T& a, const T& b){ if(b<a){ a=b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b){ if(b>a){ a=b; return true; } return false; }

template<class T> T read(){ T x; cin>>x; return x; }
template<class T> vector<T> readv(int n){ vector<T> a(n); for(int i=0;i<n;i++) cin>>a[i]; return a; }

static inline ll ceil_div(ll a, ll b){ return (a>=0 ? (a + b - 1)/b : a / b); }

// ---------- mod ops ----------
static inline int addmod(int a,int b){ int s=a+b; if(s>=MOD) s-=MOD; return s; }
static inline int submod(int a,int b){ int s=a-b; if(s<0) s+=MOD; return s; }
static inline int mulmod(ll a,ll b){ return int((a*b)%MOD); }
static int pwmod(int a, long long e){
    long long r=1, x=a%MOD; 
    while(e){ if(e&1) r=r*x%MOD; x=x*x%MOD; e>>=1; }
    return int(r);
}
static int invmod(int a){ return pwmod(a, MOD-2); }

// ---------- mint ----------
struct Mint {
    int v;
    Mint(long long x=0){ v=int((x%MOD+MOD)%MOD); }
    Mint& operator+=(const Mint& o){ v=addmod(v,o.v); return *this; }
    Mint& operator-=(const Mint& o){ v=submod(v,o.v); return *this; }
    Mint& operator*=(const Mint& o){ v=mulmod(v,o.v); return *this; }
    Mint& operator/=(const Mint& o){ return *this *= Mint(invmod(o.v)); }
    friend Mint operator+(Mint a, const Mint& b){ return a+=b; }
    friend Mint operator-(Mint a, const Mint& b){ return a-=b; }
    friend Mint operator*(Mint a, const Mint& b){ return a*=b; }
    friend Mint operator/(Mint a, const Mint& b){ return a/=b; }
    friend ostream& operator<<(ostream& os,const Mint& m){ return os<<m.v; }
};

// ---------- comb ----------
struct Comb {
    vector<int> fact, ifact;
    Comb(int n=0){ init(n); }
    void init(int n){
        fact.assign(n+1,1); ifact.assign(n+1,1);
        for(int i=1;i<=n;i++) fact[i]=mulmod(fact[i-1], i);
        ifact[n]=invmod(fact[n]);
        for(int i=n;i>0;i--) ifact[i-1]=mulmod(ifact[i], i);
    }
    int C(int n,int r){
        if(r<0||r>n) return 0;
        return mulmod(mulmod(fact[n], ifact[r]), ifact[n-r]);
    }
};

// ---------- DSU ----------
struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n=0): n(n), p(n), sz(n,1){ iota(p.begin(), p.end(), 0); }
    int find(int x){ while(x!=p[x]) x=p[x]=p[p[x]]; return x; }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
        return true;
    }
};

// ---------- Fenwick ----------
template<class T>
struct Fenwick {
    int n; vector<T> bit;
    Fenwick(int n=0): n(n), bit(n+1, T()) {}
    void add(int i, T v){ for(; i<=n; i+=i&-i) bit[i]+=v; }
    T sum_prefix(int i){ T s=T(); for(; i>0; i-=i&-i) s+=bit[i]; return s; }
    T sum_range(int l,int r){ if(r<l) return T(); return sum_prefix(r)-sum_prefix(l-1); }
};

// ---------- y_combinator ----------
template<class F>
struct Y {
    F f;
    template<class... Args>
    decltype(auto) operator()(Args&&... args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
template<class F> Y<F> yfix(F f){ return {f}; }

// ---------- pbds (GNU libstdc++ only) ----------
#ifdef __GLIBCXX__  // available with Homebrew g++ (not Apple Clang+libc++)
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  using namespace __gnu_pbds;
  template<class Key, class Cmp = less<Key>>
  using ordered_set = tree<Key, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
#endif

// ---------- solve ----------
void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if ((a + b) > n || (min(a, b) == 0 && max(a, b) > 0)){
        cout << "NO\n";
        return;
    }

    vector<int> arr_a, arr_b;

    for(int i = a + b; i > b; i--){
        arr_a.push_back(i);
        arr_b.push_back(i - b);
    }
    for(int i = b; i >= 1; i--){
        arr_a.push_back(i);
        arr_b.push_back(i + a);
    }
    for(int i = a + b + 1; i <= n; i++){
        arr_a.push_back(i);
        arr_b.push_back(i);
    }


    cout << "YES\n";
    for(auto x : arr_a) cout << x << " ";
    cout << "\n";
    for(auto x : arr_b) cout << x << " ";
    cout << "\n";
    return;
}

int main(){
    fastio();
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
