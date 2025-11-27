#include <bits/stdc++.h>
using namespace std;
/*
다익스트라 알고리즘(Dijkstra)

https://m.blog.naver.com/ndb796/221234424646
https://velog.io/@717lumos/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BCDijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#1-4-%ED%8A%B9%EC%A7%95

한 정점에서 모든 다른 정점까지의 "최단 경로"를 구하는 알고리즘
Dynamic Programming
Priority Queue
Array
BFS
*/

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
        dist.resize(V+1,INT_MAX);
    }
    void addEdge(int u,int v,int w,bool inv = true){
        G[u].push_back(Edge(w,v));
        if (inv) G[v].push_back(Edge(w,u));
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
    int get_distance(int node) {return dist[node];}
};

int main(){
    int N = 6;
    Dijkstra D(N,1);
    D.addEdge(1,2,2);
    D.addEdge(1,4,1);
    D.addEdge(2,3,3);
    D.addEdge(2,4,2);
    D.addEdge(3,6,5);
    D.addEdge(4,5,1);
    D.addEdge(5,6,2);

    D.run();

    for (int i=1;i<=N;i++){
        cout << "dis[" << i <<"] :" << D.get_distance(i) << '\n';
    }
}