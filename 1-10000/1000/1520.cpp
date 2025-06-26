#include <iostream>
#include <vector>
#include <queue>

#define ll long long 

using namespace std;


vector<vector<int>>G;

// 상 하 좌 우 
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1}; 

/*
edge[x][y] = c ; -> x,y에서 (M-1,N-1)까지 c개의 경로로 갈 수 있음
edge[x][y] = -1 -> 아직 탐색 안 함
edge[x][y] = c -> 탐색했는데 c개의 경로로
*/

int edge[500][500];

int M,N;

int DFS(int x,int y){ // x : row , y : col
    if (edge[x][y] != -1) return edge[x][y];

    edge[x][y] = 0; 


    for (int i=0;i<4;i++){
        int x_next = x + dx[i];
        int y_next = y + dy[i];

        if (x_next >= M || x_next < 0 || y_next >= N || y_next < 0 ){
            continue;
        }
        if (G[x][y] > G[x_next][y_next]){
            edge[x][y] += DFS(x_next,y_next); 
            /*
            한 정점에서 목표 지점까지 갈 수 있는 경우의 수 
            = 그 정점과 인접한 정점들에서 목표까지 갈 수 있는 경우의 수의 합
            */
        }
        
    }
    return edge[x][y];
}



int main(){
    cin >> M >> N; // M : 행 N : 열열

    G.resize(M,vector<int>(N,0));

    
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cin >> G[i][j];
            edge[i][j] = -1;
        }
    }
    edge[M-1][N-1] = 1;

    cout << DFS(0,0);
    
}


/*
경로 최적화..?

DP로 경로도 최적화 

어떻게 시간을 줄일까? 

일단 내가 선택한 방법은 DFS. 인접한 칸을 DFS로 이동해 path까지 도달하는지 본다. 
그래서 path까지 도달했다면 



*/