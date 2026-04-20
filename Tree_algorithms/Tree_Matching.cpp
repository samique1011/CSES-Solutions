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
void dfs(ll u, ll p, vector<vector<ll>>& adj, vector<vector<ll>>& dp) {

    ll sum = 0;

    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, adj, dp);
        sum += max(dp[v][0], dp[v][1]);
    }

    dp[u][0] = sum;

    dp[u][1] = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;

        dp[u][1] = max(dp[u][1],
            1 + dp[v][0] + (sum - max(dp[v][0], dp[v][1]))
        );
    }
}
void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> dp(n + 1 , vector<ll> (2 , 0));

    for(int i = 0; i < n - 1; i += 1){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1 , 1 , adj , dp);
    cout << max(dp[1][0] , dp[1][1]) << endl;
}
int main(){
    shineHere();
    solve();
}