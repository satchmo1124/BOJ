#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<vector<int>>visited;

int N,M;
int glob_max = 0;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void DFS(int x,int y,int cnt,int local_sum){
    visited[x][y] = 1;
    local_sum += v[x][y];
    cnt++;

    if (cnt < 4){
        for (int i = 0;i < 4;i++){
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M){
                continue;
            }
            if (!visited[n_x][n_y]){
                DFS(n_x,n_y,cnt,local_sum);
            }
        }
    }
    else if (cnt == 4){
        if (local_sum > glob_max){
            glob_max = local_sum;
        }
    }
    visited[x][y] = 0;
}

void FuckYou(int x,int y){
    // 0 1 2
    // 0 1 3
    // 0 2 3
    // 1 2 3
    int local_max = 0;

    int n_x,n_y;
    for (int i=0;i<4;i++){
        n_x = x + dx[i];
        n_y = y + dy[i];
        if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M){
            continue;
        }
        int r1 = v[n_x][n_y];
        for (int j=i+1;j<4;j++){
            n_x = x + dx[j];
            n_y = y + dy[j];
            if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M){
                continue;
            }
            int r2 = v[n_x][n_y];
            for (int k=j+1;k<4;k++){
                n_x = x + dx[k];
                n_y = y + dy[k];
                if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M){
                    continue;
                }
                int r3 = v[n_x][n_y];

                int s = r1 + r2 + r3 + v[x][y];
                if (s > local_max) local_max = s;
            }
        }
    }
    if (local_max > glob_max) glob_max = local_max;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    v.resize(N,vector<int>(M,0));
    visited.resize(N,vector<int>(M,0));
    
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> v[i][j];
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            DFS(i,j,0,0);
            FuckYou(i,j);
        }
    }
    cout << glob_max;
}