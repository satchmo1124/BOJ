#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,tmp;
    cin >> N;
    
    int **G = new int*[N+1];
    int **dp = new int*[N+1];
    
    for (int i=1;i<=N;i++){
        G[i] = new int[i];
        dp[i] = new int[i];
        for (int j=0;j<i;j++){
            cin >> G[i][j];
            dp[i][j] = 0;
        }
    }
    dp[1][0] = G[1][0];

    for (int i=1;i<N;i++){
        for (int j=0;j<i;j++){
            tmp = G[i+1][j] + dp[i][j];
            if (dp[i+1][j] < tmp){
                dp[i+1][j] = tmp;
            } 
            tmp = G[i+1][j+1] + dp[i][j];
            if (dp[i+1][j+1] < tmp){
                dp[i+1][j+1] = tmp;
            }
        }
    }
    int res = 0;
    for (int j=0;j<N;j++){
        if (res < dp[N][j]) res = dp[N][j];
    }
    cout << res;
}

/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
