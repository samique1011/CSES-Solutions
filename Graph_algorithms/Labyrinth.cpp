#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define shineHere() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
using namespace __gnu_pbds; 

bool isSafe(int ni , int nj , vector<vector<char>>& v){
    if(ni < 0 || nj < 0 || ni >= v.size() || nj >= v[0].size()){
        return false;
    }
    return v[ni][nj] != '#';
}

void solve(){
    int n , m;
    cin >> n >> m;

    vector<vector<char>> v(n , vector<char>(m));
    vector<vector<bool>> vis(n , vector<bool>(m , false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // R D L U
    string moves = "RDLU";

    queue<pair<int,int>> q;

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m));

    int sx, sy, ex, ey;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 'A'){
                sx = i; sy = j;
            }
            if(v[i][j] == 'B'){
                ex = i; ey = j;
            }
        }
    }

    // BFS
    q.push({sx, sy});
    vis[sx][sy] = true;

    bool found = false;

    while(!q.empty()){
        pair<int , int> rem = q.front();
        int x = rem.first;
        int y = rem.second;
        q.pop();

        if(x == ex && y == ey){
            found = true;
            break;
        }

        for(int k = 0; k < 4; k++){
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if(isSafe(nx, ny, v) && !vis[nx][ny]){
                vis[nx][ny] = true;
                parent[nx][ny] = {x, y};
                move[nx][ny] = moves[k];
                q.push({nx, ny});
            }
        }
    }

    if(!found){
        cout << "NO\n";
        return;
    }

    string path;
    int x = ex, y = ey;

    while(x != sx || y != sy){
        path.push_back(move[x][y]);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}

int main(){
    shineHere();
    solve();
}