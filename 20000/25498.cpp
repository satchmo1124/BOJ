#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>G;
vector<int>visited;
string S;



void func(int u){
    visited[u] = 1;
    int l_idx = 0;
    int l_alpha = 'a'-1;
    for (auto it = G[u].begin();it!=G[u].end();it++){
        if (!visited[*it]){
            int v = *it; // idx
            if (l_alpha < S[v]){
                l_idx = v;
                l_alpha = S[v];
            }
        }
    }
    if (l_alpha == 'a'-1){
        return;
    }
    cout << S[l_idx-1];
    func(l_idx);
}

int main(){
    int N;
    cin >> N;
    cin >> S;
    G.resize(N+1); // 1 ~ N 
    visited.resize(N+1,0);
    int u,v;




    for (int i=0;i<N-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << S[0];
    func(1);

    return 0;
}