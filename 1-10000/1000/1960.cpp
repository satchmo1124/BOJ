#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N;

int G[1002][1002] = {0,};
int chk[1002] = {0,};
int visited[1002] = {0,};
queue<int>q;

bool BFS(int* before){
    for (int i=0;i<=2*N+1;i++){
        visited[i] = 0;
    }
    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v=0;v<=2*N+1;v++){
            if (!visited[v] && G[u][v] > 0){
                q.push(v);
                visited[v] = 1;
                before[v] = u;

                if (v == 2*N+1){
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

    cin >> N;
    
    int before[1002];
    
    for (int i=1;i<=N;i++){
        cin >> G[0][i];
        chk[i] = G[0][i];
    }
    for (int i=N+1;i<=2*N;i++){
        cin >> G[i][2*N+1];
        chk[i] = G[i][2*N+1];
    }
    for (int i=1;i<=N;i++){
        for (int j=N+1;j<=2*N;j++){
            G[i][j] = 1;
        }
    }

    int path_flow;
    while(BFS(before)){
        int v = 2*N+1;
        int u = before[v];
        path_flow = G[u][v];
        
        for (;v!=0;v=u){
            u=before[v];
            if (path_flow > G[u][v]){
                path_flow = G[u][v];
            }
        }
        for (v=2*N+1;v!=0;v=u){
            u = before[v];
            G[u][v] -= path_flow;
            G[v][u] += path_flow;
        }
    }

    for (int i=1;i<=2*N;i++){
        if (i<=N && chk[i]!=G[i][0]){
            printf("-1");
            return 0;
        }
        else if (i>N && chk[i]!=G[2*N+1][i]){
            printf("-1");
            return 0;
        }
    }
    printf("1\n");

    for (int i=1;i<=N;i++){
        for (int j=N+1;j<=2*N;j++){
            printf("%d",1-G[i][j]);
        }
        printf("\n");
    }
}


/*


0
1,2...n 
n+1,....2n
2n+1
*/