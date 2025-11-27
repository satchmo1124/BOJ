#include <bits/stdc++.h>
#define INF 200000001
using namespace std;


class Dijkstra{
    struct Edge{
        int w,v;
        Edge(int w,int v) : w(w),v(v){}

        bool operator<(const Edge& other) const {
            if (w == other.w) return v > other.v;
            return w > other.w;
        }
    };
    int S;
    vector<vector<Edge>>G;
public:
    vector<int>dist;

    Dijkstra(int V,int S) : S(S){
        G.resize(V+1); 
        dist.resize(V+1,INF);
    }
    void addEdge(int u,int v,int w,bool inv = true){
        G[u].push_back(Edge(w,v));
        if (inv) G[v].push_back(Edge(w,u));
    }
    void reset(int new_start){
        S = new_start;
        fill(dist.begin(),dist.end(),INF);
    }
    void run(){
        dist[S] = 0;
        priority_queue<Edge,vector<Edge>>pq;
        pq.push(Edge(0,S));

        while(!pq.empty()){
            Edge e = pq.top(); pq.pop(); 
            for (int i=0;i<(int)G[e.v].size();i++){
                Edge next_e = G[e.v][i];
                if (dist[next_e.v] > dist[e.v] + next_e.w){
                    dist[next_e.v] = dist[e.v] + next_e.w;

                    pq.push(Edge(dist[next_e.v],next_e.v));
                }
            }
        }
    }
    void run_until(int node){
        dist[S] = 0;
        priority_queue<Edge,vector<Edge>>pq;
        pq.push(Edge(0,S));

        while(!pq.empty()){
            Edge e = pq.top(); pq.pop(); 
            for (int i=0;i<(int)G[e.v].size();i++){
                Edge next_e = G[e.v][i];
                if (dist[next_e.v] > dist[e.v] + next_e.w){
                    dist[next_e.v] = dist[e.v] + next_e.w;
                    if (next_e.v == node) return;
                    pq.push(Edge(dist[next_e.v],next_e.v));
                }
            }
        }
    }
    bool path_exist(int node){
        dist[S] = 0;
        if (node == S) return true;

        priority_queue<Edge,vector<Edge>>pq;
        pq.push(Edge(0,S));

        while(!pq.empty()){
            Edge e = pq.top(); pq.pop(); 
            for (int i=0;i<(int)G[e.v].size();i++){
                Edge next_e = G[e.v][i];
                if (dist[next_e.v] > dist[e.v] + next_e.w){
                    dist[next_e.v] = dist[e.v] + next_e.w;
                    if (next_e.v == node) return true;
                    pq.push(Edge(dist[next_e.v],next_e.v));
                }
            }
        }
        return false;
    }
    pair<bool,int> get_dist(int node){
        pair<bool,int>p;
        if (dist[node] == INF) p.first = false;
        else p.first = true;
        p.second = dist[node];
        return p;
    }
    int get_distance(int node) {return dist[node];}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,E,v1,v2;
    cin >> N >> E;

    Dijkstra graph(N,1);
    for (int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph.addEdge(u,v,w);
    }
    cin >> v1 >> v2;

    

    pair<bool,int>s_v1,s_v2,v1_v2,v1_t,v2_t;
    pair<bool,int>p1,p2;

    graph.run();
    s_v1 = graph.get_dist(v1);
    s_v2 = graph.get_dist(v2);

    graph.reset(v1);
    graph.run_until(v2);
    v1_v2 = graph.get_dist(v2);

    graph.reset(N);
    graph.run();
    v1_t = graph.get_dist(v1);
    v2_t = graph.get_dist(v2);

    p1.first = s_v1.first && v1_v2.first && v2_t.first;
    p2.first = s_v2.first && v1_v2.first && v1_t.first;
    
    
    p1.second = s_v1.second + v1_v2.second + v2_t.second;
    p2.second = s_v2.second + v1_v2.second + v1_t.second;            


    if (p1.first){
        if (p2.first){
            cout << (p1.second > p2.second ? p2.second : p1.second);
        }
        else{
            cout << p1.second;
        }
    }
    else if (p2.first){
        cout << p2.second;
    }
    else{
        cout << -1;
    }
}

/*
S -> v1 -> v2 -> T
S -> v2 -> v1 -> T
*/