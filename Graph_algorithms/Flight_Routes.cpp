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
void solve(){
    ll n , m , k;
    cin >> n >> m >> k;
    vector<vector<pair<ll , ll>>> adj(n + 1);
    vector<ll> moves(n + 1 , 0);
    for(int i = 0; i < m; i += 1){
        ll u , v , c;
        cin >> u >> v >> c;
        adj[u].pb({v , c});
    }

    priority_queue <pair<ll , ll> , vector<pair<ll , ll>> , greater<>> pq;
    pq.push({0 , 1});

    while(pq.size()){
        auto rem = pq.top();
        pq.pop();

        ll node = rem.second;
        ll wt = rem.first;

        if(moves[node] >= k) continue;

        moves[node] += 1;

        if(node == n){
            cout << wt << " ";
        }

        for(auto x : adj[node]){
            pq.push({wt + x.second , x.first});
        }
    }
}
int main(){
    shineHere();
    solve();
}