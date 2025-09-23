#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
    int flag; // true면 벽 부숨.
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int BFS(vector<vector<bool>>G,int N,int M,int K){
    if (N == 1 && M == 1){
        return 1;
    }

    vector<vector<vector<bool>>>vis(N,vector<vector<bool>>(M,vector<bool>(K,0)));
    
    Point p = Point({0,0,0});
    Point p_n;
    queue<Point>q;
    q.push(p);
    vis[0][0][0] = vis[0][0][1] = 1;

    int level = 0;

    while(!q.empty()){
        int size = q.size();
        level++;
        for (int sz=0;sz<size;sz++){
            p = q.front();
            q.pop();
            for (int i=0;i<4;i++){
                p_n = Point({p.x+dx[i],p.y+dy[i],0});

                if (0 <= p_n.x && p_n.x < N && 0 <= p_n.y && p_n.y < M){
                    if (p_n.x == N - 1 && p_n.y == M - 1){
                        level++;
                        return level;
                    }

                    if (p.flag < K){
                        if (G[p_n.x][p_n.y]){
                            p_n.flag = p.flag + 1;
                        }
                        else{
                            p_n.flag = p.flag;
                        }
                    }
                    else{
                        if (G[p_n.x][p_n.y]){
                            continue;
                        }
                        p_n.flag = K;
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
    int N,M,K;
    cin >> N >> M >> K;
    vector<vector<bool>>G(N,vector<bool>(M,0));
    MakeGraph(G,N,M);

    cout << BFS(G,N,M,K);

}

