#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
    bool flag; // 1이면 true
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int BFS(vector<vector<bool>>G,int N,int M){
    if (N == 1 && M == 1){
        return 1;
    }

    vector<vector<vector<bool>>>vis(N,vector<vector<bool>>(M,vector<bool>(2,false)));
    
    Point p = Point({0,0,false});
    Point p_n;
    queue<Point>q;
    q.push(p);
    vis[0][0][0] = vis[0][0][1] = true;

    int level = 0;

    while(!q.empty()){
        int size = q.size();
        level++;
        for (int sz=0;sz<size;sz++){
            p = q.front();
            q.pop();
            for (int i=0;i<4;i++){
                p_n = Point({p.x+dx[i],p.y+dy[i],false});

                if (0 <= p_n.x && p_n.x < N && 0 <= p_n.y && p_n.y < M){
                    if (p_n.x == N - 1 && p_n.y == M - 1){
                        level++;
                        return level;
                    }

                    if (!p.flag){
                        if (G[p_n.x][p_n.y]){
                            p_n.flag = true;
                        }
                        else{
                            p_n.flag = false;
                        }
                    }
                    else{
                        if (G[p_n.x][p_n.y]){
                            continue;
                        }
                        p_n.flag = true;
                    }
                                        
                    if (vis[p_n.x][p_n.y][p_n.flag]) continue;
                    vis[p_n.x][p_n.y][p_n.flag] = true;
                    q.push(p_n);
                }
            }
        }
    }
    return -1;
}

void MakeGraph(vector<vector<bool>>&G,int N,int M){
    for (int i=0;i<N;i++){
        string s;
        cin >> s;
        for (int j=0;j<s.length();j++){
            G[i][j] = s[j]-'0';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<vector<bool>>G(N,vector<bool>(M,0));
    MakeGraph(G,N,M);

    cout << BFS(G,N,M);

}


/*
bfs는 항상 최단거리로 가기 때문에 visited 배열이 overwrite 되는 경우는 없습니다
*/