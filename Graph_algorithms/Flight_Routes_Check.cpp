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
void dfs(int src , vector<vector<int>>& adj , vector<bool>& vis){
    vis[src] = true;

    for(auto x : adj[src]){
        if(!vis[x]){
            dfs(x , adj , vis);
        }
    }
}
void solve(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj1(n + 1) , adj2(n + 1);
    vector<bool> vis1(n + 1 , false) , vis2(n + 1 , false);

    for(int i = 0; i < m; i += 1){
        int u , v;
        cin >> u >> v;
        adj1[u].pb(v);
        adj2[v].pb(u);
    }

    dfs(1 , adj1 , vis1);
    dfs(1 , adj2 , vis2);

    for(int i = 1; i <= n; i += 1){
        if(vis1[i] == false){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }

    for(int i = 1; i <= n; i += 1){
        if(vis2[i] == false){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;


}
int main(){
    shineHere();
    solve();
}