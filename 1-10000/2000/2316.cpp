#include <bits/stdc++.h>
using namespace std;


bool BFS(const vector<vector<int>>&G,const vector<vector<int>>&C,vector<int>&before,int N,int V){
    vector<int>visited(V,0);
    queue<int>q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!visited[v] && C[u][v] > 0){
                before[v] = u;
                visited[v] = 1;
                q.push(v);
                if (v == N + 2){
                    return true;
                }
            }
        }
    }
    return false;
}


/*
uout -> vin -> vout -> uin -> uout.....
*/
void MakeGraph(vector<vector<int>>&G,vector<vector<int>>&C,int N,int P){
    int u_in,v_in,u_out,v_out;
    for (int i=1;i<=P;i++){
        cin >> u_in >> v_in;

        u_out = N + u_in;
        v_out = N + v_in; 
        
        
        // uout -> vin

        G[u_out].push_back(v_in);
        G[v_in].push_back(u_out);
        C[u_out][v_in] = 1;

        // v_in -> v_out
        G[v_in].push_back(v_out);
        G[v_out].push_back(v_in);
        C[v_in][v_out] = 1;

        // v_out -> u_in

        G[v_out].push_back(u_in);
        G[u_in].push_back(v_out);
        C[v_out][u_in] = 1;

        // u_in -> u_out

        G[u_in].push_back(u_out);
        G[u_out].push_back(u_in);
        C[u_in][u_out] = 1;

    }
}

int MaxFlow(const vector<vector<int>>&G,vector<vector<int>>&C,int N,int V){
    vector<int>before(V,0);

    int max_flow = 0;
    int u,v;
    
    while(BFS(G,C,before,N,V)){
        for (v=2;v!=1;v=u){
            u = before[v];
            C[u][v] -= 1;
            C[v][u] += 1;
        }
        max_flow++;        
        C[1][1+N] = C[2][2+N] = 1;
        C[1+N][1] = C[2+N][2] = 0;
    }
    return max_flow;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,P;
    cin >> N >> P;

    int V = 2*N + 1;
    vector<vector<int>>G(V);
    vector<vector<int>>C(V,vector<int>(V,0));
    MakeGraph(G,C,N,P);
    cout << MaxFlow(G,C,N,V);
}


/*
2 * P + N + 1
생각해보면 이정도까지 필요 X
그냥 edge당 하나만 추가 ㄱㄱ

이게 아니라 그냥 Vin , Vout 나누는게 좋으려나..
이러면 N * 2여서 메모리 초과 안 될 듯...

int = 4byte
1KB = 1024byte
1MB = 1024KB

128MB = 128 * 1024KB = 128 * 1024 * 1024byte = 128 * 1204 * 1024 / 4 = 33,554,432

*/