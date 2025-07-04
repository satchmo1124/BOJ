#include <iostream>

using namespace std;

int G[50][50] = {0,};
int visited[50][50] = {0,};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int tot = 0;
int M,N,K;

void DFS(int x,int y){
    visited[x][y] = 1;

    int nx,ny;

    for (int i=0;i<4;i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N ){ 
            if (!visited[nx][ny] && G[nx][ny]){ // Not visited && cabbage exists
                DFS(nx,ny);
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    for (int i=0;i<T;i++){
                
        cin >> M >> N >> K;

        int x,y;

        for (int i=0;i<K;i++){
            cin >> x >> y;
            G[x][y] = 1;
        }

        tot = 0;

        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++){
                if (!visited[i][j] && G[i][j] == 1 ){
                    DFS(i,j);
                    tot++;
                }
            }
        }
        cout << tot<<'\n';

        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++){
                visited[i][j] = 0;
                G[i][j] = 0;
            }
        }
    }
}