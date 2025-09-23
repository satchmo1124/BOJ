
#include <bits/stdc++.h>
using namespace std;

/*
edges[u][x] : Edge(v,cap,ref) 
=> u에서 v로 향하는 edge
*/

struct Edge{ // u -> v
    
    int v,cap,ref; // v : 도착점 cap : 용량 ref : u의 ref 번째 원소로 v가 들어있다.
    Edge(int v,int cap,int ref) : v(v),cap(cap),ref(ref) {}
};
class Dinic{
    int S,T;
    vector<vector<Edge>>edges; // graph
    vector<int>level,next_v;
public:
    Dinic(int MAX_V,int src,int sink) : S(src),T(sink) {
        edges.resize(MAX_V);
        level.resize(MAX_V);
        next_v.resize(MAX_V);
    }
    void addEdge(int u,int v,int cap,bool inv){ 
        edges[u].emplace_back(v,cap,(int)edges[v].size());
        edges[v].emplace_back(u,inv ? cap : 0,(int)edges[u].size()-1);

        /*
        u : 0 1 (v,cap,3);
        v : 0 1 2 (u,?,2);
        */

         // 왜 -1? : v 자기 자신 제외
    }
    bool bfs(){
        fill(level.begin(),level.end(),-1); // -1 : 방문 X
        queue<int>q;
        level[S] = 0;
        q.push(S);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for (auto edge : edges[u]){
                int v = edge.v, cap = edge.cap;

                if (level[v] == -1 && cap > 0){
                    level[v] = level[u] + 1;
                    //cout << "level[" << v << "] : " << level[v] << '\n';
                    q.push(v);
                }
            }
        }
        return level[T] != -1; // Sink까지 도달 여부
    }
    void reset_next_v(){
        fill(next_v.begin(),next_v.end(),0);
    }
    int dfs(int u,int max_flow){
        if (u == T)
            return max_flow;
        for (int &i=next_v[u];i<edges[u].size();i++){ // 여기서 참조자 때문에 next_v 설정됨.
            int v = edges[u][i].v, cap = edges[u][i].cap;

            if (level[u] + 1 == level[v] && cap > 0){
                int flow = dfs(v,min(max_flow,cap));
                if (flow > 0){
                    edges[u][i].cap -= flow; // u -> v
                    edges[v][edges[u][i].ref].cap += flow; // v -> u
                    return flow;
                }
            }
        }
        return 0;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int V,E;
    cin >> V >> E;
    
    
    Dinic network(V+1,1,V);
    for (int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        network.addEdge(u,v,1,false);
    }

    int INF = V + 1;
    int res = 0;
    while(network.bfs()){
        network.reset_next_v();
        while(true){
            int flow = network.dfs(1,INF);
            if (!flow) break;
            res += flow;
        }
    }
    cout << res;
}


/*
5 5
1 2
1 3
2 4
3 4
4 5

1

*/