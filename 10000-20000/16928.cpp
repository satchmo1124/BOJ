#include <bits/stdc++.h>
using namespace std;


int BFS(int G[101][1]){
    int vis[101] = {0,};
    queue<int>q;
    q.push(1);
    vis[1] = 1;

    int level = 0;

    while(!q.empty()){
        level++;
        int size = q.size();
        for (int s=0;s<size;s++){
            int u = q.front();
            q.pop();
            for (int i=1;i<=6;i++){     
                int v = u + i;
                if (vis[v]) continue;
    
                if (v == 100) return level;
                
                vis[v] = 1;
                if (G[v][0]) v = G[v][0];
                vis[v] = 1;
                
                q.push(v);
            }
        }
    }
}

void MakeGraph(int G[101][1],int N,int M){
    int u,v;
    for (int i=0;i<N+M;i++){
        cin >> u >> v;
        G[u][0] = v;
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    int G[101][1] = {0,};

    MakeGraph(G,N,M);
    cout << BFS(G);
}