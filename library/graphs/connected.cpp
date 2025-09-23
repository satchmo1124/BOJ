#include <bits/stdc++.h>
using namespace std;

bool visited[300];
vector<int>G[300];
queue<int>q;
int connected_comp = 0;

void makeGraph(int E,vector<int> *G){
    for (int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

bool connected(int V,int cur_node){
    int cnt = 0;
    visited[cur_node] = 1;
    cnt++;

    q.push(cur_node);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<G[cur_node].size();i++){
            int v = G[cur_node][i];
            if (!visited[v]){
                q.push(v);
                cnt++;
            }
        }
    }

    if (cnt == V){
        return true;
    }
    return false;
}

void ConnectedComponent(int N,int cur_node){ // with BFS
    if (visited[cur_node]) return;
    visited[cur_node] = 1;
    q.push(cur_node);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<G[cur_node].size();i++){
            int v = G[cur_node][i];
            if (!visited[v]){
                q.push(v);
            }
        }
    }
    connected_comp++;
}

int main(){
    int V,E;
    cin >> V >> E;
    vector<int>G[V+1];

    makeGraph(E,G);

    if (connected(1,0)){
        cout << "G is connected";
    }
    else{
        cout << "G is NOT connected";
    }

    ConnectedComponent(V,1);
    
}