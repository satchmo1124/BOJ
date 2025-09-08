#include <bits/stdc++.h>
using namespace std;

bool cooked,uncooked;

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

/*
-1 0 0
1 0 0
0 1 0
0 -1 0
0 0 1
0 0 -1
*/

struct Point{
    int x;
    int y;
    int z;
};

int BFS(vector<vector<vector<int>>>&G,queue<Point>q,int N,int M,int H){
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            Point p = q.front();
            q.pop();
            for (int j=0;j<6;j++){
                int x = p.x + dx[j];
                int y = p.y + dy[j];
                int z = p.z + dz[j];
                if (0 <= x && x < N && 0 <= y && y < M && 0 <= z && z < H && !G[x][y][z]){
                    G[x][y][z] = 1;
                    q.push(Point{x,y,z});
                }  
            }
        }
        level++;
    }
    level--;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            for (int k=0;k<H;k++){
                if (G[i][j][k] == 0) return -1;
            }
        }
    }

    return level;
}

queue<Point> MakeGraph(vector<vector<vector<int>>>&G,int N,int M,int H){
    queue<Point>q;
    for (int k=0;k<H;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                cin >> G[i][j][k];
                if (G[i][j][k] == 1){
                    q.push(Point{i,j,k});
                }
                if (G[i][j][k] == 0) uncooked = true;
            }
        }
    }
    return q;
}

int main(){
    int M,N,H;
    cin >> M >> N >> H;
    vector<vector<vector<int>>>G(N,vector<vector<int>>(M,vector<int>(H,0)));

    queue<Point>q = MakeGraph(G,N,M,H);

    int res;

    if (q.empty()) {
        res = -1;
    }
    else if (!uncooked){ // 1존재, but 0존재 X
        res = 0;
    }
    else{
        res = BFS(G,q,N,M,H);
    }
    cout << res;
}