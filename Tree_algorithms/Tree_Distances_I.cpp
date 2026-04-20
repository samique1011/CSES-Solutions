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

vector<vector<int>> adj;
vector<int> bfs(int start, int n){
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto &it : adj[node]){
            if(dist[it] == -1){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}

void solve(){
    int n;
    cin >> n;
    
    adj.assign(n+1, {});
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> dist1 = bfs(1, n);
    
    int A = 1;
    for(int i = 1; i <= n; i++){
        if(dist1[i] > dist1[A]) A = i;
    }

    vector<int> distA = bfs(A, n);
    int B = A;
    for(int i = 1; i <= n; i++){
        if(distA[i] > distA[B]) B = i;
    }
    vector<int> distB = bfs(B, n);
    for(int i = 1; i <= n; i++){
        cout << max(distA[i], distB[i]) << " ";
    }
    cout << "\n";
}

int main(){
    shineHere();
    solve();
}