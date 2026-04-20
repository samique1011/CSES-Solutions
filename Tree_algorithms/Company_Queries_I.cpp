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




void dfs(int src, int p , vector<vector<int>>& adj , vector<vector<int>>& bl , vector<int>& dep){
    dep[src] = dep[p] + 1;
    bl[src][0] = p;

    for(int i = 1; i < 20; i += 1){
        bl[src][i] = bl[bl[src][i-1]][i-1];
    }

    for(auto x : adj[src]){
        if(x != p)  dfs(x , src , adj , bl , dep);
    }
}
int findKParent(int u , int k , vector<vector<int>>& bl){
    for(int i = 19; i >= 0; i -= 1){
        if((1 << i) & k){
            u = bl[u][i];
        }
    }

    return (u == 0)? -1 : u;
}
void solve(){
    int n , q;
    cin >> n >> q;

    vector<vector<int>> bl(2e5 + 1 , vector<int>(20 , 0));
    vector<int> dep(2e5 + 1 , 0);

    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i += 1){
        int u;
        cin >> u;
        adj[u].pb(i);
    }

    dfs(1 , 0 , adj , bl , dep);


    for(int i = 0; i < q; i += 1){
        int node , k;
        cin >> node >> k;
        int ans = findKParent(node , k , bl);
        cout << ans << endl;
    }

}
int main(){
    shineHere();
    solve();
}