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
    int n;
    cin >> n;
    vector<pair<int  , int>> v(n);
    map<pair<int , int> , int> mp;
    for(int i = 0; i < n; i += 1){
        int x , y;
        cin >> x >> y;
        v[i] = {x , y};
        mp[{x , y}] = i;
    }

    sort(all(v) , [](pair<int , int>& a , pair<int , int>& b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return  a.first < b.first;
    });

    vi f(n , 0) , s(n , 0);
    set<ll> hs;
    for(int i = 0; i < n; i += 1){
        auto it = hs.lower_bound(v[i].second);
        if(it != hs.end())    s[mp[{v[i].first , v[i].second}]] = 1;
        hs.insert(v[i].second);
    }

    hs.clear();
    for(int i = n - 1;  i >= 0; i -= 1){
        auto it = hs.upper_bound(v[i].second);
        if(it != hs.begin())    f[mp[{v[i].first , v[i].second}]] = 1;
        hs.insert(v[i].second);
    }

    for(auto x : f) cout << x << " ";
    cout << endl;
    for(auto x : s) cout << x << " ";
    cout << endl;
}
int main(){
    shineHere();
    solve();
}