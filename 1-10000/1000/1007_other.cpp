#include <iostream>
#include <vector>
#include <math.h>
typedef unsigned long long lli;

/*
1007인데 벡터의 길이의 합으로 구함...
원래는 합의 길이를 구해야 함 ㅇㅅㅇ 

*/

using namespace std;

lli adj[20][20] = {0,};


int DFS(int dest,int N,int visited[]){
    visited[dest] = 1;

    int start = 0;
    for (int i=0;i<N;i++){
        if (!visited[i]){
            start = i;
            visited[start] = 1;
            break;
        }
    }

    lli local_min = 0;

    for (int j=start+1;j<N;j++){
        if (!visited[j]){
            lli dfs = adj[start][j] + DFS(j,N,visited);
            visited[j] = 0;
            
            if (local_min == 0 || local_min > dfs) {
                local_min = dfs;
            }
        }
    }
    visited[start] = 0;
    
    return local_min;

}


int main(){
    int T;
    cin>>T;

    for (int i=0;i<T;i++){
        int N;
        cin>>N;

        vector<pair<int,int>>P;
        

        for (int i=0;i<N;i++){
            int x,y;
            cin>>x>>y;
            P.push_back(make_pair(x,y));
        }
        


        for (int i=0;i<N-1;i++){
            for (int j=i+1;j<N;j++){
                adj[i][j] = adj[j][i] = 
                (P[i].first - P[j].first) * (P[i].first - P[j].first)  + 
                (P[i].second - P[j].second) * (P[i].second - P[j].second);
            }
        }



        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }

        int visited[20] = {0,};
        visited[0] = 1;

        lli global_min = 0; // 암튼 제일 큰 수 


        for (int i=1;i<N;i++){
            lli local_min =  adj[0][i] + DFS(i,N,visited);
            if (global_min == 0 || global_min > local_min){
                global_min = local_min;
            }
            visited[i] = 0;
            visited[0] = 1;
        }
        cout << global_min <<'\n';
        // double res = sqrt(global_min);
        // printf("%.12f",res);
    }
    
}