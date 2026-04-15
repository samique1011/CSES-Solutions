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
int dfs(ll src,  vector<vector<ll>>& adj , vector<bool>& vis , ll n , vector<ll>& dp){
    if(src == n){
        return 1;
    }

    vis[src] = true;
    for(auto x : adj[src]){
        if(vis[x]){
            dp[src] = mod_add(dp[src] , dp[x] , MOD);
        }
        else{
            ll ans = dfs(x , adj , vis , n , dp);
            dp[src] = mod_add(dp[src] , ans , MOD);
        }
    }
    return dp[src];
}
void solve(){
    ll n , m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> dp(n + 1);
    vector<bool> vis(n + 1 , false);

    for(int i = 0; i < m; i += 1){
        ll u , v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    vis[1] = true;
    dp[n] = 1;
    
    cout << dfs(1 , adj , vis , n , dp) << endl;
}
int main(){
    shineHere();
    solve();
}