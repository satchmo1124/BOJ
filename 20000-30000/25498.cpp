#include <bits/stdc++.h>
using namespace std;
/*
root 기준으로, 인접한 정점들의 문자 체크
만약 가장 사전순으로 큰 알파벳이 1개라면,해당 root로 ㄱㄱ.
만약 // 2개 이상이라면, 다른 root도 확인 후 비교.
*/
string Solve(const vector<vector<int>>&G,string S,vector<int>&visited,int root){

    visited[root] = 1;

    int max_alpha = 'a'-1;

    for (int i=0;i<G[root].size();i++){
        int v = G[root][i];
        if (!visited[v] && max_alpha < S[v]){
            max_alpha = S[v];
        } 
    }
    char node_alpha = S[root];
    
    string s_max = "";
    string tmp = "";
    for (int i=0;i<G[root].size();i++){
        int v = G[root][i];
        if (visited[v] || S[v] != max_alpha) continue;
        tmp = Solve(G,S,visited,v);
        if (s_max < tmp) s_max = tmp;
    }


    string res = "";
    res.push_back(node_alpha);
    res += s_max;

    return res;
}


void MakeGraph(vector<vector<int>>&G,int N,string &S){
    cin >> S;
    S = " " + S;
    int u,v;
    for (int i=0;i<N-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string S;    
    cin >> N;

    vector<int>visited(N+1,0);
    vector<vector<int>>G(N+1);

    MakeGraph(G,N,S);
    cout << Solve(G,S,visited,1);

}