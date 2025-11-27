#include <bits/stdc++.h>
using namespace std;

void MakeGraph(int N,int K,vector<int>&T,vector<vector<int>>&G){
    for (int i=1;i<=N;i++) cin >> T[i];

    for (int i=0;i<K;i++){
        int x,y;
        cin >> x >> y;
        G[y].push_back(x);
    }
}

int DP(int n,const vector<int>&T,const vector<vector<int>>&G,vector<int>&dp){
    if (dp[n]!=-1) return dp[n];
    int M = 0;
    for (int i=0;i<(int)G[n].size();i++){
        int dp_next = DP(G[n][i],T,G,dp);
        if (M < dp_next) M = dp_next;
    }
    dp[n] = T[n] + M;
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int N,K,W;
        cin >> N >> K;
        vector<int>T(N+1);
        vector<int>dp(N+1,-1);
        vector<vector<int>>G(N+1);
        MakeGraph(N,K,T,G);
        cin >> W;

        cout << DP(W,T,G,dp) << '\n';
    }
}