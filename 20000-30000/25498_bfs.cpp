#include <bits/stdc++.h>
using namespace std;
/*
root 기준으로, 인접한 정점들의 문자 체크
만약 가장 사전순으로 큰 알파벳이 1개라면,해당 root로 ㄱㄱ.
만약 // 2개 이상이라면, 다른 root도 확인 후 비교.
*/
string BFS(const vector<vector<int>>&G,string S,int N,int root){
    vector<int>visited(N+1,0);
    queue<int>q;
    q.push(root);
    visited[root] = 1;

    string ans = "";
    ans.push_back(S[root]);

    int now_level = 1;
    int next_level = 0;
    char max_alpha = 0;
    queue<int>tmp;

    while(!q.empty()){
        int u = q.front();
        q.pop();    

        for (int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!visited[v] && max_alpha < S[v]){
                max_alpha = S[v];
            }
        }
        tmp.push(u);

        if (--now_level != 0){
            continue;
        }
        while(!tmp.empty()){
            u = tmp.front();
            tmp.pop();
            for (int i=0;i<G[u].size();i++){
                int v = G[u][i];
                if (!visited[v] && S[v] == max_alpha){
                    visited[u] = 1;
                    q.push(v);
                    next_level++;
                }    
            }
        }
        if (max_alpha){
            ans.push_back(max_alpha);
        }

        now_level = next_level;
        next_level = 0;
        max_alpha = 0;
    }
    return ans;
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

    vector<vector<int>>G(N+1);

    MakeGraph(G,N,S);
    cout << BFS(G,S,N,1);

}

/*
틀린 이유 : 42번쨰 코드에서 visited여부도 검사해야함. 안 그러면 이미 지나간 부모 노드를 다시 갈 수도...
*/