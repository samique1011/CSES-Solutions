#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define vi vector<int>
#define vl vector<long long>
#define shineHere()                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(v) v.begin(), v.end()
#define vin                     \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
ll modInverse(ll a, ll b) { return expo(a, b - 2, b); }

ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, modInverse(b, m), m) + m) % m;
}
ll ns(ll num) { return (num * (num + 1)) / 2; }
ll sbCount(ll n) { return __builtin_popcount(n); }
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> dp(n + 1, -1);
    vector<ll> indeg(n + 1, 0);
    queue<ll> q;
    vector<ll> p(n + 1);
    iota(all(p), 0);
    vector<ll> topo;
    bool flag = false;

    dp[1] = 1;

    for (int i = 0; i < m; i += 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indeg[v] += 1;
    }

    for (int i = 1; i <= n; i += 1)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        ll rem = q.front();
        q.pop();
        topo.pb(rem);

        for (auto x : adj[rem])
        {
            indeg[x] -= 1;
            if (indeg[x] == 0)
            {
                q.push(x);
            }
        }
    }

    for (auto x : topo)
    {
        if (dp[x] == -1)
            continue;

        for (auto y : adj[x])
        {
            if (dp[x] + 1 > dp[y])
            {
                dp[y] = dp[x] + 1;
                p[y] = x;
            }
        }
    }

    if(dp[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    ll i = n;
    vector<ll> ans;
    while (p[i] != i)
    {
        ans.pb(i);
        i = p[i];
    }
    ans.pb(1);
    cout << ans.size() << endl;
    reverse(all(ans));
    for (auto j : ans)
    {
        cout << j << " ";
    }
}
int main()
{
    shineHere();
    solve();
}