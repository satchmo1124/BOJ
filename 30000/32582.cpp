#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
using namespace  std;

int N;

int visited[4] = {0,};

queue<int>q;

bool bfs(int G[4][4], int* before){
    for (int i=0;i<4;i++){
        visited[i] = 0;
    }

    q.push(0);
    visited[0] =1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v=0;v<4;v++){
            if (!visited[v] && G[u][v] > 0 ){
                q.push(v);
                visited[v] = 1;
                before[v] = u;

                if (v==3){
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int before[4];
    
    
    int global_flow = INT_MAX;
    

    for (int i=0;i<N;i++){

        int U[4][4] = {0,};
        int D[4][4] = {0,};

        int up_flow = 0; 
        int down_flow = 0;

        cin >> U[0][1]; 
        cin >> U[1][3]; 
        cin >> U[1][2]; // later need to also consider U[2][1];
        cin >> U[0][2]; 
        cin >> U[2][3];

        D[0][1] = U[0][1];
        D[1][3] = U[1][3];
        D[2][1] = U[1][2];
        D[0][2] = U[0][2];
        D[2][3] = U[2][3];

        while(bfs(U,before)){
            int v = 3;
            int u = before[v];
            int path_flow = U[u][v];

            for (;v!=0;v=u){
                u = before[v];
                if (path_flow > U[u][v]){
                    path_flow = U[u][v];
                }
            }
            for (v=3;v!=0;v=u){
                u = before[v];
                U[u][v] -= path_flow;
                U[v][u] += path_flow;
            }
            up_flow += path_flow;
        }


        while(bfs(D,before)){
            int v = 3;
            int u = before[v];
            int path_flow = D[u][v];

            for (;v!=0;v=u){
                u = before[v];
                if (path_flow > D[u][v]){
                    path_flow = D[u][v];
                }
            }
            for (v=3;v!=0;v=u){
                u = before[v];
                D[u][v] -= path_flow;
                D[v][u] += path_flow;
            }
            down_flow += path_flow;
        }

        //printf("%d\n",MAX(up_flow,down_flow));

        global_flow = MIN(global_flow,MAX(up_flow,down_flow));
    }
    cout << global_flow;
}