#include <bits/stdc++.h>
using namespace std;


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

struct Point{
    int x,y;
};

int BFS(vector<vector<bool>>&G,int N,int M,Point start,Point end){
    vector<vector<bool>>vis(N,vector<bool>(M,0));
    
    int level = 0;

    queue<Point>q;
    q.push(start);

    while(!q.empty()){
        int size = q.size();
        level++;
        for (int i=0;i<size;i++){
            Point p = q.front();
            q.pop();
            for (int j=0;j<4;j++){
                Point p_n = Point({p.x+dx[j],p.y+dy[j]});
                if (p_n.x == end.x && p_n.y == end.y){
                    level++;
                    return level;
                }
                
                if (0 <= p_n.x && p_n.x < N && 
                    0 <= p_n.y && p_n.y < M && 
                    !vis[p_n.x][p_n.y] && G[p_n.x][p_n.y]){
                    vis[p_n.x][p_n.y] = 1;
                    q.push(p_n);
                }
            }    
        }
    }

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
    int N,M;
    cin >> N >> M;
    
    Point start = Point({0,0});
    Point end = Point({N-1,M-1});

    vector<vector<bool>>G(N,vector<bool>(M,0));
    
    MakeGraph(G,N,M);

    cout << BFS(G,N,M,start,end);
}