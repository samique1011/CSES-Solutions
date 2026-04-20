#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define vi vector<int> 
#define vl vector<long long>
#define shineHere() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(v) v.begin() , v.end()
#define vin for(int i = 0; i < n; i++) cin >> v[i];


using namespace std;
using namespace __gnu_pbds; 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll modInverse(ll a, ll b) {return expo(a, b - 2, b);}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, modInverse(b, m), m) + m) % m;}
ll ns(ll num) {return (num * (num + 1))/2;}
ll sbCount(ll n) {return __builtin_popcount(n);}
ll fp(ll x , vl& p){
    if(p[x] == x)   return x;
    else    return p[x] = fp(p[x] , p);
}
bool merge(ll u , ll v , vl& p , vl& r){
    ll pu = fp(u , p);
    ll pv = fp(v , p);

    if(pu == pv)    return false;
    else if(r[pu] > r[pv]){
        p[pv] = pu;
    }
    else if(r[pu] < r[pv]){
        p[pu] = pv;
    }
    else{
        p[pv] = pu;
        r[pu] += 1;
    }
    return true;
}
void solve(){
    ll n , m ;
    cin >> n >> m;
    vl p(n + 1 , 0) , r(n + 1 , 0);
    iota(all(p) , 0);

    vector<vector<ll>> edges;
    for(int i = 0; i < m; i += 1){
        ll u , v , c;
        cin >> u >> v >> c;
        edges.pb({u , v , c});
    }

    sort(all(edges) , [](vl& a , vl& b){
        return a[2] < b[2];
    });

    ll wt = 0;
    for(int i = 0; i < m; i += 1){
        if(merge(edges[i][0] , edges[i][1] , p , r)){
            wt += edges[i][2];
        }
    }

    //if there are two or more msts then it is impossible
    ll cnt = 0;
    for(int i = 1; i <= n; i += 1){
        if(fp(i , p) == i)  cnt += 1;
    }

    if(cnt > 1) cout << "IMPOSSIBLE" << endl;
    else    cout << wt << endl;

}
int main(){
    shineHere();
    solve();
}