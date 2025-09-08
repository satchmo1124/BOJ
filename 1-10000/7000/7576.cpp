#include <bits/stdc++.h>
using namespace std;

bool cooked,uncooked;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct Point{
    int x;
    int y;
};

int BFS(vector<vector<int>>&G,queue<Point>q,int N,int M){
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            Point p = q.front();
            q.pop();
            for (int j=0;j<4;j++){
                int x = p.x + dx[j];
                int y = p.y + dy[j];
                if (0 <= x && x < N && 0 <= y && y < M && !G[x][y]){
                    G[x][y] = 1;
                    q.push(Point{x,y});
                }  
            }
        }
        level++;
    }
    level--;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (G[i][j] == 0) return -1;
        }
    }

    return level;
}

queue<Point> MakeGraph(vector<vector<int>>&G,int N,int M){
    queue<Point>q;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> G[i][j];
            if (G[i][j] == 1) {
                q.push(Point{i,j});
            }
            if (G[i][j] == 0) uncooked = true;
        }
    }
    return q;
}

int main(){
    int M,N;
    cin >> M >> N;
    vector<vector<int>>G(N,vector<int>(M,0));

    queue<Point>q = MakeGraph(G,N,M);

    int res;

    if (q.empty()) {
        res = -1;
    }
    else if (!uncooked){ // 1존재, but 0존재 X
        res = 0;
    }
    else{
        res = BFS(G,q,N,M);
    }
    cout << res;
}



/*

원소  1(익은 토마토), 0(안 익은 토마토), -1(빈 칸)

Case
0만 있는 경우 => -1
-1만 있는 경우 => -1

0,-1만 있는 경우.
=> -1

즉 1이 없는 경우 -> -1

1이 있는 경우.
처음 1 위치를 큐에 넣고 BFS.





출력 : N(자연수),0(이미 익음),-1(못 익음)

-1인 경우는? -> 토마토가 빈 칸(-1)로 둘러쌓인 경우(disconnected)
=> connected component 구하기

0인 경우는 -> 인풋 받을때 체크 ㄱㄱ



*/