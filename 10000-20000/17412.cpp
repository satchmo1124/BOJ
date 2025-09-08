#include <bits/stdc++.h>
using namespace std;

/*
서로 다른 경로의 최대 개수 : MaxFlow
간선의 용량을 1로 잡으면 경로수 = Flow기 때문이다. 
*/

int G[401][401] = {0,};
queue<int>q;
int visited[401] = {0,};


bool BFS(int N,int *before){
    for (int i=1;i<=N;i++){
        visited[i] = 0;
    }

    q.push(1);
    visited[1] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v=1;v<=N;v++){
            if (!visited[v] && G[u][v] > 0){ // 조건 흠...
                q.push(v);
                visited[v] = 1;
                before[v] = u;

                if (v == 2){
                    while(!q.empty()){
                        q.pop();
                    }
                    return true;
                }
            }
        }    
    }
    return false;
}

int main(){
    int N,P;
    cin >> N >> P;

    int u,v,max_flow=0;
    for (int i=0;i<P;i++){
        cin >> u >> v;
        G[u][v] = 1;
    }

    int *before = new int[N+1];
    while(BFS(N,before)){
        for (v=2;v!=1;v=u){
            u = before[v];
            G[u][v] -= 1;
            G[v][u] += 1;
        }
        max_flow++;
    }
    cout << max_flow;
}