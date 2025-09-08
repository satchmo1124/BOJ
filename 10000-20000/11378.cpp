#include <bits/stdc++.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;

int src,sink;

bool BFS(const vector<vector<int>>&G,const vector<vector<int>>&C,int V,vector<int>&before){
    vector<int>visited(V,0);
    queue<int>q;
    q.push(src);
    visited[src] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!visited[v] && C[u][v] > 0) {
                q.push(v);
                visited[v] = 1;
                before[v] = u;

                if (v == sink){
                    return true;
                }
            }
        }
    }
    return false;
}

void MakeGraph(vector<vector<int>>&G,vector<vector<int>>&C,int N,int M,int K){
    // 0. Src,Sink 초기화
    src = N + M + 2;
    sink = N + M + 1;

    // 1. 0노드와 1~N직원 사이 , 1~N 직원과 1~M 일 사이 간선 생성
    int E,u,v;

    for (u=1;u<=N;u++){
        cin >> E;
        G[0].push_back(u);
        G[u].push_back(0);
        C[0][u] = K+1;
        
        for (int j=0;j<E;j++){
            cin >> v;
            v += N;

            G[u].push_back(v);
            G[v].push_back(u);
            C[u][v] = 1;
        }
    }

    // 2. 1~M 일과 Sink 사이 용량이 poss_flow[i]인 간선 생성
    for (int i=1;i<=M;i++){
        G[i+N].push_back(sink);
        G[sink].push_back(i+N);
        C[i+N][sink] = 1;
    }
    // 3. Src와 0노드 사이 간선 생성
    G[src].push_back(0);
    G[0].push_back(src);
    C[src][0] = K + N;
   
}
void re_initialize(vector<vector<int>>&G,vector<vector<int>>&C,int N,int M,int K){
    C[src][0] = K;
    for (int u=1;u<=N;u++) C[0][u] = K;
}

int MaxFlow(const vector<vector<int>>&G,vector<vector<int>>&C,int V){
    
    int path_flow = 1;
    int max_flow = 0;
    vector<int>before(V);    
    
    while(BFS(G,C,V,before)){
        int v = sink;
        int u = before[v];

        for (v = sink;v!=src;v=u){
            u = before[v];
            C[u][v] -= path_flow;
            C[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K,V;
    cin >> N >> M >> K;
    
    V = N + M + 3;

    vector<vector<int>>G(V); // Adjacent List
    vector<vector<int>>C(V,vector<int>(V,0)); // capacity

    MakeGraph(G,C,N,M,K);

    C[src][0] = N;
    for (int u=1;u<=N;u++){
        C[0][u] = 1;
    }

    int r1 = MaxFlow(G,C,V);
    re_initialize(G,C,N,M,K);
   
    int r2 = MaxFlow(G,C,V);

    cout << r1 + r2;
}

/*
마지막에 src에서 sink로 가는 flow만 계산해줌.


*/








/*
MakeGraph에서 Src에서 0까지 용량이 K+N인 이유:
N명의 직원이 받은 벌점을 각각 a1,a2,...aN이라 할 때, Sum(ai) = K
이때 각각 할 수 있는 일은 a1+1,a2+1,...aN+1이다. 
이를 모두 더하면 sum(ai)+N = K + N이다. 
*/



/*
//int poss_flow[M+1]; // i번째 일을 몇 명의 직원이 할 수 있는지.
    //memset(poss_flow,0,sizeof(poss_flow));
    //vector<int>poss_flow(M+1,0);
            //poss_flow[v]+=1;
        //C[i+N][sink] = poss_flow[i];


*/