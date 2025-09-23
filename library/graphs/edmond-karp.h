#pragma once
#include "../ps_header.h"


struct Edge{
    int v,cap,ref;
    Edge(int v,int cap,int ref) : v(v),cap(cap),ref(ref) {}
    Edge() : v(0),cap(0),ref(0) {}
};


class EdMondKarp {
    int S,T;
    vector<vector<Edge>>edges;
    vector<int>vis,before,before_edge;

public:
    EdMondKarp(int MAX_V,int src,int sink) : S(src),T(sink){
        edges.resize(MAX_V);
        vis.resize(MAX_V);
        before.resize(MAX_V);
        before_edge.resize(MAX_V);
    }
    void addEdge(int u,int v,int cap,bool inv){
        edges[u].emplace_back(v,cap,(int)edges[v].size());
        edges[v].emplace_back(u,inv ? cap : 0, (int)edges[u].size()-1);
    }
    bool bfs(){
        fill(before.begin(),before.end(),-1);
        queue<int>q;
        q.push(S);
        before[S] = S;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for (int i=0;i<(int)edges[u].size();i++){
                auto &e = edges[u][i];
                if (before[e.v] == -1 && e.cap > 0){
                    before[e.v] = u;
                    before_edge[e.v] = i; // u -> v 로 갈 때의 i
                    if (e.v == T) return true;
                    q.push(e.v);
                }
            }
        }
        return false;
    }
    int Augmentation(){
        int max_flow = INT_MAX;
        for (int v=T;v!=S;v=before[v]){
            int u = before[v];
            auto &e = edges[u][before_edge[v]];
            max_flow = min(e.cap,max_flow);
        }
        for (int v = T; v != S; v = before[v]){
            int u = before[v];
            auto &e = edges[u][before_edge[v]];
            e.cap -= max_flow;
            edges[v][e.ref].cap += max_flow;
        }
        return max_flow;
    }
    int MaxFlow(){
        int flow = 0;
        while(bfs()){
            flow += Augmentation();
        }
        return flow;
    }
};