#include <bits/stdc++.h>
using namespace std;

void MakeGraph(int E,vector<vector<int>>&G){
    int u,v;
    for (int i=0;i<E;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

bool BFS(int src,vector<int>&color,vector<vector<int>>G){
    queue<int>q;
    q.push(src);
    color[src] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!color[v]){
                color[v] = -color[u];
                q.push(v);
            }
            else{
                if (color[v] != -color[u]) return false;
            }
        }
    }
    return true;
}

bool is_bipartite(int V,vector<vector<int>>G){
    vector<int>color(V+1,0);
    for (int i=1;i<=V;i++){
        if (!color[i]){
            if (BFS(i,color,G)) {
                continue;
            }
            return false;
        }
    }
    return true;
}

int main(){
    int V,E,K;
    cin >> K;
    for (int i=0;i<K;i++){
        cin >> V >> E;
        vector<vector<int>>G(V+1);
        MakeGraph(E,G);
        if (is_bipartite(V,G)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}