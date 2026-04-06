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
ll sbCount(ll n) {return __builtin_popcount(n);}\
bool isSafe(int i , int j , vector<vector<char>>& g , vector<vector<bool>>& vis){
    if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size()){
        return false;
    }
    if(vis[i][j]|| g[i][j] == '#')    return false;
    return true;
}
void bfs(int i , int j , vector<vector<char>>& g , vector<vector<bool>>& vis){
    queue<pair<int , int>> q;
    vector<vector<int>> dist = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
    q.push({i , j});

    while(q.size()){
        auto rem = q.front();
        q.pop();

        for(int x = 0; x < 4; x += 1){
            int ni = rem.first + dist[x][0];
            int nj = rem.second + dist[x][1];

            if(isSafe(ni , nj , g , vis)){
                vis[ni][nj] = true;
                q.push({ni , nj});
            }
        }
    }
}
void solve(){
    int n , m;
    cin >> n >> m;
    vector<vector<char>> g(n , vector<char>(m));
    vector<vector<bool>> vis(n , vector<bool>(m , false));
    for(int i = 0; i < n;  i += 1){
        for(int j = 0; j < m; j += 1){
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < m; j += 1){
            if(g[i][j] == '.' && !vis[i][j]){
                vis[i][j] = true;
                bfs(i , j , g , vis);
                cnt += 1;
            }
        }
    }

    cout << cnt << endl;
}
int main(){
    shineHere();
    solve();
}