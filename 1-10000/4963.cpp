#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};


void BFS(const vector<vector<bool>>&G,vector<vector<bool>>&vis,Point p,int h,int w){
    queue<Point>q;
    q.push(p);
    vis[p.x][p.y] = 1;

    Point p_n;


    while(!q.empty()){
        p = q.front();
        q.pop();
        for (int i=0;i<8;i++){
            p_n.x = p.x + dx[i];
            p_n.y = p.y + dy[i];
            if (0 <= p_n.x && p_n.x < h && 0 <= p_n.y && p_n.y < w){
                if (!vis[p_n.x][p_n.y] && G[p_n.x][p_n.y]){
                    vis[p_n.x][p_n.y] = 1;
                    q.push(p_n);
                }
            }
        }
    }
}

int Solve(vector<vector<bool>>&G,int h,int w){
    vector<vector<bool>>vis(h,vector<bool>(w,0));

    int level = 0;
    Point p;

    for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                if (!vis[i][j] && G[i][j]){
                    p = Point({i,j});
                    BFS(G,vis,p,h,w);
                    level++;
                }
            }
    }
    return level;
}

void MakeGraph(vector<vector<bool>>&G,int h,int w){
    int tmp;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> tmp;
            if (tmp) G[i][j] = true;
            else G[i][j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w,h;
    while(1){
        cin >> w >> h;

        if (w == 0 && h == 0) return 0;

        vector<vector<bool>>G(h,vector<bool>(w,0));
        MakeGraph(G,h,w);
       
        cout << Solve(G,h,w) << '\n';
    }
}