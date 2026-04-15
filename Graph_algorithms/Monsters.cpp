#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve(){
    int n , m;
    cin >> n >> m;

    vector<vector<char>> g(n , vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    vector<vector<int>> d = {{0,1},{1,0},{0,-1},{-1,0}};

    vector<vector<int>> distM(n , vector<int>(m , 1e9));
    queue<pair<int,int>> mq;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'M'){
                mq.push({i,j});
                distM[i][j] = 0;
            }
        }
    }

    while(!mq.empty()){
        auto rem = mq.front(); mq.pop();
        int i = rem.first;
        int j = rem.second;

        for(auto &dir : d){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(ni>=0 && nj>=0 && ni<n && nj<m && g[ni][nj] != '#' && distM[ni][nj] == 1e9){
                distM[ni][nj] = distM[i][j] + 1;
                mq.push({ni,nj});
            }
        }
    }

    vector<vector<int>> distA(n , vector<int>(m , 1e9));
    vector<vector<pair<int,int>>> parent(n , vector<pair<int,int>>(m , {-1,-1}));
    vector<vector<char>> move(n , vector<char>(m));

    queue<pair<int,int>> aq;

    int si, sj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'A'){
                si = i;
                sj = j;
            }
        }
    }

    aq.push({si , sj});
    distA[si][sj] = 0;

    while(!aq.empty()){
        auto rem = aq.front(); aq.pop();
        int i = rem.first;
        int j = rem.second;

        if(i == 0 || j == 0 || i == n-1 || j == m-1){
            string path = "";

            while(!(i == si && j == sj)){
                path += move[i][j];
                auto pr = parent[i][j];
                i = pr.first;
                j = pr.second;
            }

            reverse(path.begin(), path.end());

            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            return;
        }

        for(int k = 0; k < 4; k++){
            int ni = i + d[k][0];
            int nj = j + d[k][1];

            if(ni>=0 && nj>=0 && ni<n && nj<m && g[ni][nj] != '#'){
                
                if(distA[i][j] + 1 < distM[ni][nj] && distA[ni][nj] == 1e9){

                    distA[ni][nj] = distA[i][j] + 1;
                    parent[ni][nj] = {i,j};

                    if(k == 0) move[ni][nj] = 'R';
                    if(k == 1) move[ni][nj] = 'D';
                    if(k == 2) move[ni][nj] = 'L';
                    if(k == 3) move[ni][nj] = 'U';

                    aq.push({ni,nj});
                }
            }
        }
    }

    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}