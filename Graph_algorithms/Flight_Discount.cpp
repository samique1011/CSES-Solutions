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
void helper(vector<vector<pair<ll , ll>>>& adj , vector<ll>& dist , ll src){
    priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<>> pq;
    pq.push({0 , src});
    dist[src] = 0;

    while(pq.size()){
        auto rem = pq.top();
        pq.pop();

        ll wt = rem.first;
        ll node = rem.second;

        if(dist[node] < wt)    continue;

        for(auto x : adj[node]){
            ll v = x.first;
            ll wt2 = x.second;

            if(dist[node] + wt2 < dist[v]){
                dist[v] = dist[node] + wt2;
                pq.push({dist[v] , v});
            }
        }
    }

}
void solve(){
    int n , m;
    cin >> n >> m;

    vector<vector<pair<ll , ll>>> adj1(n + 1);
    vector<vector<pair<ll , ll>>> adj2(n + 1);
    vector<vector<ll>> edges;

    for(int i = 0; i < m; i += 1){
        ll u , v , c;
        cin >> u >> v >> c;
        adj1[u].pb({v , c});
        adj2[v].pb({u , c});
        edges.pb({u , v , c});
    }

    vector<ll> dist1(n + 1 , LLONG_MAX);
    vector<ll> dist2(n + 1 , LLONG_MAX);

    helper(adj1 , dist1 , 1);
    helper(adj2 , dist2 , n);

    ll mini = LLONG_MAX;
    for(int i = 0; i < m; i += 1){
        if(dist1[edges[i][0]] != LLONG_MAX && dist2[edges[i][1]] != LLONG_MAX){
            ll tc = dist1[edges[i][0]] + edges[i][2] / 2 + dist2[edges[i][1]];
            mini = min(mini , tc);
        } 
    }

    cout << mini << endl;
}
int main(){
    shineHere();
    solve();
}